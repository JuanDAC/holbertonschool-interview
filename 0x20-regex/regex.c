#include "regex.h"

/**
 * regex_match - compare two strings if one has slight regex
 * @str: regular string
 * @pattern: string that might have regex . and/or regex *
 * Return: 1 if they "match", 0 if not.
 */
int regex_match(char const *str, char const *pattern)
{
	int check_dot = 0, check_star = 0;

	if (!str || !pattern)
		return (0);

	check_dot = *str && (*str == *pattern || *pattern == '.');
	check_star = *(pattern + 1) == '*';

	if (!*str && !check_star)
		return (*pattern ? 0 : 1);

	if (check_dot && check_star)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	if (check_dot && !check_star)
		return (regex_match(str + 1, pattern + 1));
	if (check_star)
		return (regex_match(str, pattern + 2));

	return (0);
}