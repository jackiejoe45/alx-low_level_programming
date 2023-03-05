#include "main.h"
/**
  * _memcpy - copies a memory area
  * @dest: destination pointer
  * @src: source pointer
  * @n: number of bytes to be copied
  * Return: destination
  */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *p = dest;

	while (n--)
	{
		*p++ = *src++;
	}
	return (dest);
}
