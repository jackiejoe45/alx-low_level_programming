#include "main.h"
#include <stdio.h>
/**
  * _strncpy - copies a string
  * @dest: destination
  * @src: source
  * @n: number of bytes
  * Return: char type
  */
char *_strncpy(char *dest, char *src, int n)
{
	char *result = dest;

	while (*src && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return (result);
}
