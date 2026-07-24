#file_reader.py
from pathlib import Path
path = Path("/Users/arpitsingh/Desktop/python_folder/function_introduction.py")

# now we need to read from the path 
contents = path.read_text()

print(contents)