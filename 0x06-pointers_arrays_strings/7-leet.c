#include "main.h"
#include <stdio.h>
/**
  * leet - encodes a string into 1337O (leetcode)
  * @str : char array
  * Return: char type
  */
char *leet(char *str)
{
	int i, j;
	char leet_map[128] = { 0 };
	
	leet_map['a'] = leet_map['A'] = '4';
	leet_map['e'] = leet_map['E'] = '3';
	leet_map['o'] = leet_map['O'] = '0';
	leet_map['t'] = leet_map['T'] = '7';
	leet_map['l'] = leet_map['L'] = '1';
	
	for (i = 0; str[i] != '\0'; i++)
	{
		if (leet_map[str[i]] != 0)
		{
			str[i] = leet_map[str[i]];
		}
	}
	return (str);
}
