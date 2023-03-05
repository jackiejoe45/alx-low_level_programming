#include "main.h"
/**
  * _strspn - gets the length of a prefix substring
  * @s: pointer to the string to b searched
  * @accept: pointer to string containing allowed characters
  * Return: length of substring
  */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;

	while (*s != '\0' && strchr(accept, *s) != NULL)
	{
		count++;
		s++;
	}
	return (count);
}
