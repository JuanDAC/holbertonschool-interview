#include "palindrome.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int exponent(const int base, int n)
{
    if (n == 0)
        return 1;
    return base * exponent(base, n - 1);
}

int palindrome(unsigned long n, unsigned long initial, int base, int length)
{
    int lastBase = 0;
    if (!length)
    {
        if (n == 0 && base != 0)
            return (exponent(10, (base - 1)));

        if (n == 0)
            return (0);

        lastBase = palindrome(n / 10, initial, base + 1, 0);

        if (base != 0)
            return (lastBase);
        else
            length = lastBase;
    }
    if (length)
    {
        lastBase = length;
        if (n == 0)
            return (1);
        return (
            (initial / lastBase % 10) == (n % 10) &&
            palindrome(n / 10, initial, base + 1, lastBase / 10));
    }

    return (0);
}
