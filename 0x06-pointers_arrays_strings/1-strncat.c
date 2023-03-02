#include "main.h"
#include <stdio.h>
/**
  * _strncat - concatenates two strings
  * @dest:destination string
  * @src:source string
  * @n:number of bytes
  * Return: char type
  */
char *_strncat(char *dest, char *src, int n)
{
	char *result = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
	return (result);
}
