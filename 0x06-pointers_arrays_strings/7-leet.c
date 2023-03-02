#include "main.h"
#include <stdio.h>
/**
  * leet - encodes a string into 1337O (leetcode)
  * @str : char array
  * Return: char type
  */
char *leet(char *str)
{
	char *ptr = str;
	char leet_chars[] = "aAeEoOtTlL";
	char leet_nums[] = "44337011";
	int i, j;

	while (*ptr)
	{
		i = 0;
		while (leet_chars[i])
		{
			if (*ptr == leet_chars[i])
			{
				*ptr = leet_nums[i];
				break;
			}
			i++;
		}
		ptr++;
	}
	return (str);
}
