#include "main.h"
/**
  * _strlen_recursion - returns the lengthh of a string
  * @s: String
  * Return: none
  */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	return (1 + _strlen_recursion(s + 1));
}
