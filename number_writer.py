#number_writer.py

from pathlib import Path 
import json 

numbers = [23,12,101 , 456]

content = json.dumps(numbers);

path = Path("/Users/arpitsingh/Desktop/python_folder/json_dumper.py")

path.write_text(content)

path1 = Path("json_dumper.py")

content1 = path1.read_text()

print(content1)
