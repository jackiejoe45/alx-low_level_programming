#include "main.h"
/**
 * check_palindrome - checks if a string is a palindrome recursively
 * @s: string
 * @start: starting index
 * @end: ending index
 * Return: 1 if palindrome, 0 if not palindrome
 */
int check_palindrome(char *s, int start, int end)
{
	if (start >= end)
	{
		return (1);
	}
	if (s[start] != s[end])
	{
		return (0);
	}
	return (check_palindrome(s, start + 1, end - 1));
}
/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string
 * Return: 1 if palindrome, 0 if not palindrome
 */
int is_palindrome(char *s)
{
	int len = strlen(s);

	return (check_palindrome(s, 0, len - 1));
}
