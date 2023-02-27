#include "main.h"
/**
  * _strcpy - copies the string pointed by src to the buffer pointedby dest
  * @dest: dest
  * @src: src
  * Return:dest
  */
char *_strcpy(char *dest, char *src)
{
	char *p = dest;

	while (*src != '\0')
	{
		*p++ = *src++;
	}
	*p = '\0';
	return (dest);
}
