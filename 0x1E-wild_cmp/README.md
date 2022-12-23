# 0x1E. Wild Compare

## Details

By: Alexa Orrico, Software Engineer at Holberton School Weight: 1Project will startNov 28, 2022 12:00 AM, must end byDec 2, 2022 12:00 AMwas released atNov 30, 2022 12:00 AM An auto review will be launched at the deadline## Requirements

### General

- Allowed editors: `vi` , `vim` , `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl)
  and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)

- You are not allowed to use `global` or `static` variables
- No more than 5 functions per file
- You are not allowed to use the standard library.
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `holberton.h`
- Don’t forget to push your header file
- You are not allowed to use loops of any kind

## Tasks

### 0. Wild Compare

          mandatory         Progress vs Score  Task Body Write a function that compares two strings and returns   ` 1 `   if the strings can be considered identical, otherwise return   ` 0 `  .

- Prototype: `int wildcmp(char *s1, char *s2);`
- `s2` can contain the special character `*` .
- The special char `*` can replace any string (including an empty string)

```bash
alexa@ubuntu:~/0x1E-wild_cmp$ cat 0-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    r = wildcmp("main.c", "*.c");
    printf("%d\n", r);
    r = wildcmp("main.c", "m*a*i*n*.*c*");
    printf("%d\n", r);
    r = wildcmp("main.c", "main.c");
    printf("%d\n", r);
    r = wildcmp("main.c", "m*c");
    printf("%d\n", r);
    r = wildcmp("main.c", "ma********************************c");
    printf("%d\n", r);
    r = wildcmp("main.c", "*");
    printf("%d\n", r);
    r = wildcmp("main.c", "***");
    printf("%d\n", r);
    r = wildcmp("main.c", "m.*c");
    printf("%d\n", r);
    r = wildcmp("main.c", "**.*c");
    printf("%d\n", r);
    r = wildcmp("main-main.c", "ma*in.c");
    printf("%d\n", r);
    r = wildcmp("main", "main*d");
    printf("%d\n", r);
    r = wildcmp("abc", "*b");
    printf("%d\n", r);
    return (0);
}
alexa@ubuntu:~/0x1E-wild_cmp$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-wildcmp.c -o 0-wildcmp
alexa@ubuntu:~/0x1E-wild_cmp$ ./0-wildcmp
1
1
1
1
1
1
1
0
1
1
0
0
alexa@ubuntu:~/0x1E-wild_cmp$

```

Task URLs Github information Repo:

- GitHub repository: `holbertonschool-interview`
- Directory: `0x1E-wild_cmp`
- File: `0-wildcmp.c`
  Self-paced manual review Panel footer - Controls