#include "main.h"
/**
  * _strpbrk - searches a string for any of a set of bytes
  * @s: string to be searched
  * @accept: string cointaining accepted bytes
  * Return: s or null
  */
char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		if (strchr(accept, *s) != NULL)
		{
			return (s);
		}
		s++;
	}
	return (NULL);
}
