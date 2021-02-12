#include "palindrome.h"

/**
 *is_palindrome: function that checks if a number is palindrome
 *
 *@n: the number to check
 *
 *Return: 1 if is palindrome and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long num = n;
	unsigned long neo = 0;

	while (num != 0)
	{
		neo *= 10;
		neo += num % 10;
		num /= 10;
	}
	if (neo == n)
		return (1);
	return (0);
}