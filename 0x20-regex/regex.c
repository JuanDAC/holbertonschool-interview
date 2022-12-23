#include "regex.h"

/**
 * regex_match - compare two strings if one has slight regex
 * @str: regular string
 * @pattern: string that might have regex . and/or regex *
 * Return: 1 if they "match", 0 if not.
 */
int regex_match(char const *str, char const *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return (1);
	if (*str == *pattern && *(pattern + 1) != '*')
		return (regex_match(str + 1, pattern + 1));
	if (*str == *pattern && *(pattern + 1) == '*')
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	if (*str != *pattern && *(pattern + 1) == '*')
		return (regex_match(str, pattern + 2));
	return (0);
}
