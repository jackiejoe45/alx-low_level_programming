#include "main.h"
/**
 * match - recursively checks if two strings match
 * @s1: string 1
 * @s2: string 2
 * @s1_next: next character in string 1
 * @s2_next: next character in string 2
 * Return: 1 if match, 0 if not
 */
int match(char *s1, char *s2, char *s1_next, char *s2_next)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}
	if (*s2 == '*')
	{
		s2_next = s2 + 1;
		if (*s2_next == '\0')
		{
			return (1);
		}
		s1_next = s1;
	}
	if (*s1 == *s2)
	{
		s1_next = s1 + 1;
		s2_next = s2 + 1;
		return (match(s1_next, s2_next, s1_next, s2_next));
	}
	if (*s1 != '\0' && *s2_next == '\0')
	{
		return (0);
	}
	if (*s1_next != '\0' && *s2 == '\0')
	{
		return (match(s1_next, s2_next, s1_next, s2_next));
	}
	return (match(s1_next, s2, s1_next, s2_next));
}
/**
 * wildcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if same, 0 if different
 */
int wildcmp(char *s1, char *s2)
{
	return (match(s1, s2, s1, s2));
}
