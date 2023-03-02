#include "main.h"
#include <stdio.h>
/**
  * cap_string - Capitalizes all words of a string
  * @str : char array
  * Return: char type
  */
char *cap_string(char *str)
{
	char *ptr = str;
	int capitalize_next = 1;

	while (*ptr)
	{
		if (capitalize_next && (*ptr >= 'a' && *ptr <= 'z'))
		{
			*ptr = *ptr - 32;
		}
		if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n')
		{
			capitalize_next = 1;
		}
		else if (*ptr == ',' || *ptr == ';')
		{
			capitalize_next = 1;
		}
		else if (*ptr == '.' || *ptr == '!')
		{
			capitalize_next = 1;
		}
		else if (*ptr == '?' || *ptr == '"')
		{
			capitalize_next = 1;
		}
		else if (*ptr == '(' || *ptr == ')')
		{
			capitalize_next = 1;
		}
		else if (*ptr == '{' || *ptr == '}')
		{
			capitalize_next = 1;
		}
		else
		{
			capitalize_next = 0;
		}
		ptr++;
	}
	return (str);
}
