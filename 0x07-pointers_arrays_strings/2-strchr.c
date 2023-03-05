#include "main.h"
/**
  * _strchr - locates a character in a string
  * @s: pointer to the string to be serached
  * @c: character to search for
  * Return: s or null
  */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (*s == c)
	{
		return (s);
	}
	return (NULL);
}
