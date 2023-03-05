#include "main.h"
/**
  * _memset - fills memory with a constant byte
  * @s: pointer
  * @b: value to be filled
  * @n: number of bytes to fill
  * Return: s
  */
char *_memset(char *s, char b, unsigned int n)
{
	char *p = s;

	while (n--)
	{
		*p++ = b;
	}
	return (s);
}
