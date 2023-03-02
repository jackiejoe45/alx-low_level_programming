#include "main.h"
#include <stdio.h>
/**
  * _strcat - concatenates two strings
  * @dest: dest string
  * @src: src string
  * Return: char pointer
  */
char *_strcat(char *dest, char *src);
{
	char *result = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (result);
}
