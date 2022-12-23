#include "regex.h"

/**
 * regex_match - compare two strings if one has slight regex
 * @str: regular string
 * @pattern: string that might have regex . and/or regex *
 * Return: 1 if they "match", 0 if not.
 */
int regex_match(char const *str, char const *pattern)
{
	int tmp = 0;

	if (*str == '\0' && *pattern == '\0')
		return (1);
	if (*str == '\0' && *pattern == '*')
		return (regex_match(str, pattern + 1));
	if (*str == '\0' || *pattern == '\0')
		return (0);
	if (*str == *pattern || *pattern == '.')
		return (regex_match(str + 1, pattern + 1));
	if (*pattern == '*')
	{
		if (*(pattern - 1) == *str || *(pattern - 1) == '.')
			tmp = regex_match(str + 1, pattern);
		return (regex_match(str, pattern + 1) || tmp);
	}
	return (0);
}
