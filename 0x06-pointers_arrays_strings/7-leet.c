#include "main.h"
#include <stdio.h>
/**
  * leet - encodes a string into 1337O (leetcode)
  * @ch : char array
  * Return: char type
  */
char *leet(char *ch)
{
	int i=0, j;
	char leet[9] = { 'O','L','?','E','A','?','?','T','\0' };

	while (ch[i] != '\0')
	{
		j = 0;

		while (leet[j] != '\0')
		{
			if (ch[i] == leet[j] + 32 || ch[i] == leet [j])
			{
				ch[i]= j + '0';
			}
			j++;
		}
		i++;
	}
	return (ch);
