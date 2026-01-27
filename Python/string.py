str = "   Hello world! WELCOME to Python!!   "

print("1st letter to the 10th letter\n" + str[:10] + '\n')

print("10th letter to the last letter\n" + str[10:] + '\n')

print("to upper\n" + str.upper() + '\n')

print("to lower\n" + str.lower() + '\n')

print("strip a delimiter from the beginning and the end\n" + str.strip(' ') + '\n')

print("Replace string\n" + str.replace('l', '8') + '\n')

print("split a string with the spevific delimiter")
print(str.split(" "))

print("\nString concatenation")
print(str + "abcdef\n")

print("f (function) string ")
age = 10
str2 = f"my age is {age}"
print(str2 + '\n')
