import streamlit as st
import cv2
import numpy as np
import mediapipe as mp
from gtts import gTTS
import tempfile
import os
import time

st.set_page_config(page_title="AI Sign Language Interpreter", layout="wide")
st.title("🖐️ AI Interpreter for Sign Language in Video Calls")
st.markdown("""
This app uses AI to recognize American Sign Language (ASL) gestures from your webcam and translates them into spoken or written text in real-time, making virtual meetings more inclusive for hearing-impaired individuals.
""")

# Note: This is a simplified mapping for demonstration.  A real application would use a trained model.
# Consider expanding this to include more signs or using a comprehensive ASL dataset.
ASL_ALPHABET = {
    0: 'A', 1: 'B', 2: 'C', 3: 'D', 4: 'E',
    5: 'F', 6: 'G', 7: 'H', 8: 'I', 9: 'J',
    10: 'K', 11: 'L', 12: 'M', 13: 'N', 14: 'O',
    15: 'P', 16: 'Q', 17: 'R', 18: 'S', 19: 'T',
    20: 'U', 21: 'V', 22: 'W', 23: 'X', 24: 'Y', 25: 'Z'
}

# Initialize MediaPipe Hands with error handling
mp_hands = mp.solutions.hands
mp_drawing = mp.solutions.drawing_utils
hands = mp_hands.Hands(
    static_image_mode=False,
    max_num_hands=1,
    min_detection_confidence=0.7,
    min_tracking_confidence=0.5
)  # Consider adding error handling here, e.g., try-except block for initialization

if hands is None:
    st.error("Failed to initialize MediaPipe Hands. Please ensure you have the necessary libraries installed.")
    st.stop()

col1, col2 = st.columns([2, 1])

if 'output_text' not in st.session_state:
    st.session_state.output_text = ""
if 'last_sign' not in st.session_state:
    st.session_state.last_sign = ""
if 'last_sign_time' not in st.session_state:
    st.session_state.last_sign_time = time.time()  # Initialize with current time

def classify_sign(hand_landmarks):
    # In a real application, replace this with your sign language classification model.
    # For example:  return your_model.predict(features_from_landmarks(hand_landmarks))
    # Dummy classifier: randomly pick a letter for demo
    idx = np.random.randint(0, 26)
    return ASL_ALPHABET.get(idx, "")

def text_to_speech(text):
    if not text or text == st.session_state.last_sign:
        return

    current_time = time.time()
    if current_time - st.session_state.last_sign_time < 2:
        return
    try:
        tts = gTTS(text=text, lang='en')
        with tempfile.NamedTemporaryFile(delete=False, suffix=".mp3") as fp:
            temp_filename = fp.name
            tts.save(temp_filename)
        audio_bytes = open(temp_filename, "rb").read()
        col2.audio(audio_bytes, format="audio/mp3")
        os.unlink(temp_filename)
        st.session_state.last_sign = text
        st.session_state.last_sign_time = current_time
    except Exception as e:
        st.error(f"Text-to-speech error: {str(e)}")

def capture_and_process():
    cap = cv2.VideoCapture(0)
    if not cap.isOpened():
        st.error("Could not open webcam. Please check your camera connection and permissions.")
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
    frame_placeholder = col1.empty()
    stop_button_pressed = col2.button("🛑 Stop Detection")
    last_detected_sign = ""
    while cap.isOpened() and not stop_button_pressed:
        ret, frame = cap.read()
        if not ret:
            st.warning("Unable to capture frame from webcam.")
            break

        frame = cv2.flip(frame, 1)
        image_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        results = hands.process(image_rgb)

        current_sign = ""
        if results.multi_hand_landmarks:
            for hand_landmarks in results.multi_hand_landmarks:
                # Improve landmark drawing: customize colors and connections
                drawing_spec = mp_drawing.DrawingSpec(thickness=2, circle_radius=3, color=(0, 255, 0))  # Green
                connection_drawing_spec = mp_drawing.DrawingSpec(thickness=2, color=(255, 0, 0)) # Blue
                mp_drawing.draw_landmarks(
                    frame,
                    hand_landmarks,
                    mp_hands.HAND_CONNECTIONS,
                    landmark_drawing_spec=drawing_spec,
                    connection_drawing_spec=connection_drawing_spec
                )
                current_sign = classify_sign(hand_landmarks)

        # Display webcam feed with dynamic caption
        frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB) # Convert back to RGB for display
        if current_sign:
            caption = f"Webcam Feed - Sign Detected: {current_sign}"
        else:
            caption = "Webcam Feed - No Sign Detected"
        frame_placeholder.image(frame, channels="RGB", caption=caption, use_container_width=True)

        # Only update if a new sign is detected and it's not empty
        if current_sign and current_sign != last_detected_sign:
            st.session_state.output_text += current_sign
            text_to_speech(current_sign)
            # Consider displaying a history of detected signs, not just the current one
            # This can be done with a list in st.session_state
            # st.session_state.detected_signs.append(current_sign)
            # col2.markdown(f"**Detected Signs:** {', '.join(st.session_state.detected_signs)}")
            last_detected_sign = current_sign
        else:
            pass # No changes needed if no new sign is detected. The caption in the image display handles this.

        # Display the accumulated output text
        col2.markdown(f"### Output Text:\n{st.session_state.output_text}")

        # Control frame rate to reduce CPU usage
        time.sleep(0.05)  # Adjust this value as needed

    cap.release()

    # Indicate that detection has stopped
    col2.write("Detection stopped. Click 'Start Webcam' to begin again.")

if col2.button("🎥 Start Webcam"):
    capture_and_process()

col2.button("🧹 Clear Output", on_click=lambda: st.session_state.update({"output_text": "", "last_sign": ""}))

# Consider adding error handling for webcam access and model loading.