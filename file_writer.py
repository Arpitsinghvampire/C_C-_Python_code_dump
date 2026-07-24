#file_writer.py
from pathlib import Path

path = Path("/Users/arpitsingh/Desktop/python_folder/function_introduction1.py")

path1 = Path("/Users/arpitsingh/Desktop/python_folder/function_introduction.py")
content = path1.read_text()

path.write_text(content)

content1 = path.read_text()

print(content1)