Curriculum Specializations Average: 71.61%\* [

                  Foundations


                  Average: 103.37%

](https://intranet.hbtn.io/curriculums/1/observe)

- [Specializations Average: 71.61%](https://intranet.hbtn.io/curriculums/2/observe)

You are currently connected as Student Switch to: [Staff](https://intranet.hbtn.io/users/switch_viewing_as_permission_group?group=staff)

|  # 0x1C. Island Perimeter

## Details

By: Alexa Orrico, Software Engineer at Holberton School Weight: 1Project will startNov 14, 2022 12:00 AM, must end byNov 18, 2022 12:00 AMwill be released atNov 16, 2022 12:00 AM An auto review will be launched at the deadline## Requirements

### General

- Allowed editors: `vi` , `vim` , `emacs`
- All your files will be interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
- All your files should end with a new line
- The first line of all your files should be exactly `#!/usr/bin/python3`
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the `PEP 8` style (version 1.7)
- You are not allowed to import any module
- All modules and functions must be documented
- All your files must be executable

## Tasks

### 0. Island Perimeter

          mandatory         Progress vs Score  Task Body Create a function   ` def island_perimeter(grid): `   that returns the perimeter of the island described in   ` grid `  :

- `grid` is a list of list of integers:\* 0 represents water
- 1 represents land
- Each cell is square, with a side length of 1
- Cells are connected horizontally/vertically (not diagonally).
- `grid` is rectangular, with its width and height not exceeding 100

- The grid is completely surrounded by water
- There is only one island (or nothing).
- The island doesn’t have “lakes” (water inside that isn’t connected to the water surrounding the island).

```bash
guillaume@ubuntu:~/0x1C$ cat 0-main.py
#!/usr/bin/python3
"""
0-main
"""
island_perimeter = __import__('0-island_perimeter').island_perimeter

if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    print(island_perimeter(grid))

guillaume@ubuntu:~/0x1C$
guillaume@ubuntu:~/0x1C$ ./0-main.py
12
guillaume@ubuntu:~/0x1C$

```

Task URLs Github information Repo:

- GitHub repository: `holbertonschool-interview`
- Directory: `0x1C-island_perimeter`
- File: `0-island_perimeter.py`
  Self-paced manual review Panel footer - Controls
  Copyright © 2022 Holberton Inc, All rights reserved.
