import streamlit as st
import cv2
import numpy as np
import mediapipe as mp  
from gtts import gTTS
import os
import tempfile
import time
import pickle
from sklearn.ensemble import RandomForestClassifier
import logging  # for general-purpose logging

# Set up page config
st.set_page_config(page_title="Advanced ASL Interpreter", layout="wide")

# Title and description
st.title("🤟 Advanced ASL Interpreter for Video Calls")
st.markdown("""
This app detects **American Sign Language (ASL)** alphabet gestures from your webcam and translates them to text in real-time.
""") 


try:
    from transformers import AutoProcessor, AutoModelForImageClassification

    # Load model and processor from Hugging Face Hub
    processor = AutoProcessor.from_pretrained("prithivMLmods/Alphabet-Sign-Language-Detection")
    model = AutoModelForImageClassification.from_pretrained("prithivMLmods/Alphabet-Sign-Language-Detection")
    st.success("ASL model loaded successfully!", icon="✅")
except ImportError as e:
    st.error(f"Could not import necessary libraries: {e}. Please install transformers.", icon="❌")
    st.stop() # Stop the app if the import fails
except Exception as e:
    st.error(f"Failed to load ASL model: {e}", icon="❌")
    st.stop()


# The sign language model's label mapping. Update this if the model card has different labels!
label_map = {
    "0": "A", "1": "B", "2": "C", "3": "D", "4": "E", "5": "F",
    "6": "G", "7": "H", "8": "I", "9": "J", "10": "K", "11": "L",
    "12": "M", "13": "N", "14": "O", "15": "P", "16": "Q", "17": "R",
    "18": "S", "19": "T", "20": "U", "21": "V", "22": "W", "23": "X",
    "24": "Y", "25": "Z" # Assuming 26 classes for A-Z (adjust as needed)
}

# Setup MediaPipe Hands (keep this part)
mp_hands = mp.solutions.hands
mp_drawing = mp.solutions.drawing_utils
hands = mp_hands.Hands(
    static_image_mode=False,
    max_num_hands=1,  # Better performance with single hand
    min_detection_confidence=0.7,
    min_tracking_confidence=0.5
)

# Create layout
col1, col2 = st.columns([2, 1])

# Initialize session state
if 'output_text' not in st.session_state:
    st.session_state.output_text = ""
if 'last_sign' not in st.session_state:
    st.session_state.last_sign = ""
if 'last_sign_time' not in st.session_state:
    st.session_state.last_sign_time = 0
if 'frame_count' not in st.session_state:
    st.session_state.frame_count = 0

# Update the classification function to use the Hugging Face model
def classify_sign(hand_landmarks):
    # Extract relevant landmarks (example: x, y coordinates of all landmarks)
    landmarks = [[lm.x, lm.y] for lm in hand_landmarks.landmark]
    # Flatten the list for the model
    input_data = np.array(landmarks).flatten()
    # Reshape to (1, num_landmarks * 2) - batch size 1, your feature size
    input_data = input_data.reshape(1, -1)
    # Convert to tensor (PyTorch in this case) - adjust if your model is in a different framework
    import torch  
    input_tensor = torch.tensor(input_data, dtype=torch.float32)
    with torch.no_grad(): # No need to track gradients during inference
      outputs = model(input_tensor)
      logits = outputs.logits
    predicted_class_id = torch.argmax(logits, dim=-1).item()  # Get the class with highest probability
    return label_map.get(str(predicted_class_id), "") # Get the label from the mapping

# Optimized text-to-speech with rate limiting
def text_to_speech(text):
    if not text or text == st.session_state.last_sign:
        return
        
    current_time = time.time()
    if current_time - st.session_state.last_sign_time < 2:  # Rate limit to 2 seconds
        return
        
    try:
        tts = gTTS(text=text, lang='en')
        with tempfile.NamedTemporaryFile(delete=True, suffix=".mp3") as fp: # delete=True for auto-cleanup
            temp_filename = fp.name
            tts.save(temp_filename)  # Save the TTS audio to a temporary file.
        audio_bytes = open(temp_filename, "rb").read()
        col2.audio(audio_bytes, format="audio/mp3")
        os.unlink(temp_filename)
        
        st.session_state.last_sign = text
        st.session_state.last_sign_time = current_time 
    except Exception as e:
        st.error(f"Text-to-speech error: {str(e)}")

# Optimized webcam capture with frame skipping
def capture_and_process():
    cap = cv2.VideoCapture(0)
    if not cap.isOpened():
        st.error("Could not open webcam. Please check your camera connection.")
        return  # Exit the function if the webcam can't be opened
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)  # Standard resolution for balance of speed and clarity
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
    
    frame_placeholder = col1.empty()
    stop_button_pressed = col2.button("🛑 Stop Detection")
    
    while cap.isOpened() and not stop_button_pressed:
        st.session_state.frame_count += 1
        
        # Skip frames for better performance (process every 3rd frame)
        if st.session_state.frame_count % 3 != 0:
            ret = cap.grab()  # Grab frame without decoding
            continue
            
        ret, frame = cap.read()
        if not ret:
            st.warning("Unable to access webcam.")
            break
            
        # Convert to RGB and flip horizontally
        frame = cv2.flip(frame, 1)
        image_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        
        # Process for hand detection
        results = hands.process(image_rgb)
        
        current_sign = ""
        
        if results.multi_hand_landmarks:
            for hand_landmarks in results.multi_hand_landmarks:
                # Draw hand landmarks
                mp_drawing.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS,
                                          mp_drawing.DrawingSpec(color=(0, 255, 0), thickness=2, circle_radius=3),  # Green
                                          mp_drawing.DrawingSpec(color=(255, 0, 0), thickness=2, circle_radius=1)   # Blue
                                          )
                
                # Classify the sign 
                # (Only classify if landmarks are detected, avoid unnecessary processing)
                current_sign = classify_sign(hand_landmarks)

        else:
            current_sign = ""

        # Update output
        if current_sign:
            st.session_state.output_text += current_sign
            text_to_speech(current_sign)
        
        # Display the frame
        frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        frame_placeholder.image(frame, channels="RGB", use_container_width=True, caption=f"Detected: {current_sign}" if current_sign else "No sign detected")
        
        # Small delay to reduce CPU usage
        time.sleep(0.05)
    
        cap.release()

# UI Elements
with col2:
    st.subheader("Controls")
    if st.button("🎥 Start Webcam"):
        capture_and_process()
    
    st.subheader("Translation Output")
    output_placeholder = st.empty()
    if st.session_state.output_text:
        output_placeholder.markdown(f"### ✍️ Detected Text:\n{st.session_state.output_text}")
    else:
        output_placeholder.markdown("### ✍️ Detected Text:\nNo signs detected yet.")
    
    if st.button("🧹 Clear Text"):
        st.session_state.output_text = ""
        output_placeholder.markdown("### ✍️ Detected Text:\nNo signs detected yet.")

# Add instructions and information
with st.sidebar:
    st.markdown("## 📚 Instructions")
    st.markdown("""

1. Click **Start Webcam** to begin.
2. Show ASL alphabet signs to your camera.
3. The app will detect and translate signs
4. Click **Stop Detection** when finished

## 🎯 Current Features

- Detects ASL alphabet (A-Z)
- Real-time translation
- Text-to-speech output
- Optimized performance
""")
    st.markdown("## ⚠️ Limitations")
    st.markdown("""
- Demo uses random letters (no real model).
- Works best with one hand.
- Requires good lighting.
""")
    st.markdown("## 🚀 Next Steps")
    st.markdown("""
- Integrate proper ASL recognition model.
- Add phrase/sentence support.
- Improve accuracy with more training data.
""")

# Custom CSS for a more professional look
css = """
  .stApp {
    background-color: #f0f2f6;
  }
  .stButton>button {
    background-color: #2e86ab;
    color: white;
    border: none;
    padding: 0.5rem 1rem;
    border-radius: 0.25rem;
    font-weight: 500;
  }
  .stButton>button:hover {
    background-color: #1e6091;
  }
  .stTextInput>div>div>input {
    background-color: white;
    border: 1px solid #ccc;
    border-radius: 0.25rem;
    padding: 0.5rem;
  }
  .stAudio>audio {
    width: 100%;
  }
  .stMarkdown h1, .stMarkdown h2, .stMarkdown h3, .stMarkdown h4, .stMarkdown h5, .stMarkdown h6 {
    color: #1e6091;
  }
"""
st.markdown(f"<style>{css}</style>", unsafe_allow_html=True)

logging.basicConfig(level=logging.ERROR, format='%(asctime)s - %(levelname)s - %(message)s') 
from transformers import pipeline

pipe = pipeline("image-classification", model="prithivMLmods/Alphabet-Sign-Language-Detection")
pipe("https://huggingface.co/datasets/huggingface/documentation-images/resolve/main/hub/parrots.png")
