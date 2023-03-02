#include "main.h"
#include  <stdio.h>
/**
  * rot13 - encodes a string with rot-13
  * @str :char array
  * Return: char type
  */
char *rot13(char *str)
{
	char *ptr = str;
	int i;

	while (*ptr)
	{
		for (i = 0; i < 13; i++)
		{
			if (*ptr >= 'a' && *ptr < 'n' || *ptr >= 'A' && *ptr < 'N')
			{
				*ptr += 13;
				break;
			}
			else if (*ptr >= 'n' && *ptr <= 'z' || *ptr >= 'N' && *ptr <= 'Z')
			{
				*ptr -= 13;
				break;
			}
		}
		ptr++;
	}
	return (str);
}
