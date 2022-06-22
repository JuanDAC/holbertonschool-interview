#include "palindrome.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * exponent - return the exponent n of base
 *
 * @base: Arguments represent the base
 * @n: Arguments represent the exponent
 *
 * Return: Returns the exponent n of base
 */
int exponent(const int base, int n)
{
	if (n == 0)
		return (1);
	return (base * exponent(base, n - 1));
}

/**
 * palindrome - return 0 if not is a palindrome number otherwise return 1
 *
 * @n: Arguments the number to parser
 * @initial: Arguments the initial number to parse
 * @base: Arguments the represent the aument to base
 * @lastBase: Arguments the represent the last to base
 *
 * Return: Returns the exponent n of base
 */
int palindrome(unsigned long n, unsigned long initial, int base, int lastBase)
{

	if (!lastBase)
	{
		if (n == 0 && base != 0)
			return (exponent(10, (base - 1)));

		if (n == 0)
			return (0);

		lastBase = palindrome(n / 10, initial, base + 1, 0);

		if (base != 0)
			return (lastBase);
	}
	if (lastBase)
	{
		if (n == 0)
			return (1);

		return (
			(initial / lastBase % 10) == (n % 10) &&
			palindrome(n / 10, initial, base + 1, lastBase / 10));
	}

	return (0);
}
