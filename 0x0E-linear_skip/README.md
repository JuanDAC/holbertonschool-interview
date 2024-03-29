Curriculum Specializations Average: 57.75%\* [

                  Foundations


                  Average: 103.37%

](https://intranet.hbtn.io/curriculums/1/observe)

- [
  Specializations

                  Average: 57.75%

](https://intranet.hbtn.io/curriculums/2/observe)

            You are currently connected as Student            Switch to:            [Staff](https://intranet.hbtn.io/users/switch_viewing_as_permission_group?group=staff)

|  [You have a captain's log due before 2022-10-02 (in 2 days)! Log it now!](https://intranet.hbtn.io/captain_logs/122970/edit)

# 0x0E. Linear search in skip list

## Details

By: Alexandre Gautier, Software Engineer at Holberton School Weight: 1Project over - took place fromAug 1, 2022 12:00 AMto Aug 5, 2022 12:00 AM An auto review will be launched at the deadline#### In a nutshell…

- Auto QA review: 0.0/4 mandatory
- Altogether:  0.0%\* Mandatory: 0.0%
- Optional: no optional tasks

## Requirements

### General

- Allowed editors: `vi` , `vim` , `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All your files should end with a new line
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl)
  and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)

- You are not allowed to use global variables
- No more than 5 functions per file
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `search.h`
- Don’t forget to push your header file
- All your header files should be include guarded

## More Info

### search.h file

Please define the following data structure in your `search.h` header file:

```bash
#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 * for Holberton project
 */
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;

skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);
skiplist_t *linear_skip(skiplist_t *head, int value);

#endif /* _SEARCH_H_ */

```

## Tasks

### 0. Linear search in a skip list

          mandatory         Progress vs Score           Score: 0.00% (Checks completed: 0.00%)         Task Body Looking for a specific value in a singly linked list always leads to browse every element of the list.A common way to optimize the time complexity of a search in a singly linked list is to modify the list itself by adding an “express lane” to browse it.A linked list with an express lane is called a  [skip list](https://intranet.hbtn.io/rltoken/lGL3SR3eFS6dNV915Vu_Yg)

.
Write a function that searches for a value in a sorted skip list of integers.

- Prototype : `skiplist_t *linear_skip(skiplist_t *list, int value);`
- Where `list` is a pointer to the head of the skip list to search in
- A node of the express lane is placed every index which is a multiple of the square root of the size of the list (see example below)
- And `value` is the value to search for
- You can assume that `list` will be sorted in ascending order
- Your function must return a pointer on the first node where `value` is located
- If `value` is not present in `list` or if `head` is `NULL` , your function must return `NULL`
- Every time you compare a value in the list to the value you are searching, you have to print this value (see example below)
  NOTE: [You can find here](https://intranet.hbtn.io/rltoken/H6JMx-aUZSlvuh2p2tvDhg)
  the functions used in the example. You don’t need to push them, we will compile your file with our own implementation during the correction. BUT, don’t forget to push `search.h`

```bash
alex@~/0x0E-linear_skip$ cat 0-main.c
#include <stdio.h>
#include <stdlib.h>

#include "search.h"

skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    skiplist_t *list, *res;
    int array[] = {
        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    list = create_skiplist(array, size);
    print_skiplist(list);

    res =  linear_skip(list, 53);
    printf("Found %d at index: %lu\n\n", 53, res->index);
    res =  linear_skip(list, 2);
    printf("Found %d at index: %lu\n\n", 2, res->index);
    res =  linear_skip(list, 999);
    printf("Found %d at index: %p\n", 999, (void *) res);

    free_skiplist(list);
    return (EXIT_SUCCESS);
}
alex@~/0x0E-linear_skip$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-linear_skip.c skiplist/*.c -lm -o 0-linear_skip
alex@~/0x0E-linear_skip$ ./0-linear_skip
List :
Index[0] = [0]
Index[1] = [1]
Index[2] = [2]
Index[3] = [3]
Index[4] = [4]
Index[5] = [7]
Index[6] = [12]
Index[7] = [15]
Index[8] = [18]
Index[9] = [19]
Index[10] = [23]
Index[11] = [53]
Index[12] = [61]
Index[13] = [62]
Index[14] = [76]
Index[15] = [99]

Express lane :
Index[0] = [0]
Index[4] = [4]
Index[8] = [18]
Index[12] = [61]

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [8] and [12]
Value checked at index [8] = [18]
Value checked at index [9] = [19]
Value checked at index [10] = [23]
Value checked at index [11] = [53]
Found 53 at index: 11

Value checked at index [4] = [4]
Value found between indexes [0] and [4]
Value checked at index [0] = [0]
Value checked at index [1] = [1]
Value checked at index [2] = [2]
Found 2 at index: 2

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [12] and [15]
Value checked at index [12] = [61]
Value checked at index [13] = [62]
Value checked at index [14] = [76]
Value checked at index [15] = [99]
Found 999 at index: (nil)
alex@~/0x0E-linear_skip$

```

Task URLs Github information Repo:

- GitHub repository: `holbertonschool-interview`
- Directory: `0x0E-linear_skip`
- File: `0-linear_skip.c, search.h`
  Self-paced manual review Panel footer - Controls
  Copyright © 2022 Holberton Inc, All rights reserved.
