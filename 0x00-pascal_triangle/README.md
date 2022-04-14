            You are currently connected as Student            Switch to:            [Staff](https://intranet.hbtn.io/users/switch_viewing_as_permission_group?group=staff)

|  # 0x00. Pascal's Triangle

## Details

      By Alexa Orrico, Software Engineer at Holberton School          Weight: 1                Ongoing project - started Apr 11, 2022 , must end by Apr 15, 2022           - you're done with 0% of tasks.              Checker was released at Apr 13, 2022 12:00 AM        An auto review will be launched at the deadline      ## Tasks

### 0. Pascal's Triangle

          mandatory         Progress vs Score  Task Body Create a function   ` def pascal_triangle(n): `   that returns a list of lists of integers representing the Pascal’s triangle of   ` n `  :

- Returns an empty list if `n <= 0`
- You can assume `n` will be always an integer

```bash
guillaume@ubuntu:~/0x00$ cat 0-main.py
#!/usr/bin/python3
"""
0-main
"""
pascal_triangle = __import__('0-pascal_triangle').pascal_triangle

def print_triangle(triangle):
    """
    Print the triangle
    """
    for row in triangle:
        print("[{}]".format(",".join([str(x) for x in row])))


if __name__ == "__main__":
    print_triangle(pascal_triangle(5))

guillaume@ubuntu:~/0x00$
guillaume@ubuntu:~/0x00$ ./0-main.py
[1]
[1,1]
[1,2,1]
[1,3,3,1]
[1,4,6,4,1]
guillaume@ubuntu:~/0x00$

```

Task URLs Github information Repo:

- GitHub repository: `holbertonschool-interview`
- Directory: `0x00-pascal_triangle`
- File: `0-pascal_triangle.py`
  Self-paced manual review Panel footer - Controls
  Copyright © 2022 Holberton Inc, All rights reserved.
