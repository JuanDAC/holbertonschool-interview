
#include "substring.h"

/**
 * find_substring - finds all the possible substrings containing a list
 * of words,
 * within a given string.
 * @s: is the string to scan
 * @words: is the array of words all substrings must be a concatenation
 * arrangement of
 * @nb_words: is the number of elements in the array words
 * @n: holds the address at which to store the number of elements in the
 * returned array.
 * Return: an allocated array, storing each index in s, at which a substring
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *result = NULL;
	int i, j, k, l, m, len, word_len, count, found;
	char *tmp;

	if (s == NULL || words == NULL || nb_words == 0 || n == NULL)
		return (NULL);
	*n = 0;
	len = strlen(s);
	word_len = strlen(words[0]);
	result = malloc(sizeof(int) * len);
	if (result == NULL)
		return (NULL);
	for (i = 0; i < len - nb_words * word_len + 1; i++)
	{	tmp = strdup(s);
		if (tmp == NULL)
		{
			free(result);
			return (NULL);
		}
		count = 0;
		for (j = 0; j < nb_words; j++)
		{	found = 0;
			for (k = i; k < len - word_len + 1; k += word_len)
				if (strncmp(tmp + k, words[j], word_len) == 0)
				{
					for (l = k; l < k + word_len; l++)
						tmp[l] = ' ';
					count++;
					found = 1;
					break;
				}
			if (found == 0)
				break;
		}
		if (count == nb_words)
			result[(*n)++] = i;
		free(tmp);
	}
	return (result);
}
