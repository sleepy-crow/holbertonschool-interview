#include "regex.h"

/**
 * regex_match - function that compares two strings
 * @str: is the estring to compare
 * @pattern: is the base to the comparation
 * 
 * Return: 1 if the strings are equal and 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	int tmp = 0, temp = 0;

	if (!str || !pattern)
		return (0);

	tmp = *str && (*str == *pattern || *pattern == '.');
	temp = *(pattern + 1) == '*';

	if (!*str && !temp)
		return (*pattern ? 0 : 1);

	else if (tmp && temp)
		return (regex_match(str + 1, pattern) ||
			regex_match(str, pattern + 2));

	else if (tmp && !temp)
		return (regex_match(str + 1, pattern + 1));

	else if (temp)
		return (regex_match(str, pattern + 2));
	return (0);
}
