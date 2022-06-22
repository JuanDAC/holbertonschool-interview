#ifndef _PALINDROME_H
#define _PALINDROME_H

int palindrome(unsigned long n, unsigned long initial, int base, int lastBase);

#define is_palindrome(N) palindrome((N), (N), 0, 0)

#endif /* _PALINDROME_H */
