#include "main.h"
#include <stdio.h>
/**
  * string_toupper - changes lowercase letters to uppercase
  * @str: character
  *Return: char type
  */
char *string_toupper(char *str)
{
	char *ptr = str;

	while (*ptr)
	{
		if (*ptr >= 'a' && *ptr <= 'z')
		{
			*ptr = *ptr - 32;
		}
		ptr++;
	}
	return (str);
}
