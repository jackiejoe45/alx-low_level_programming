#include "main.h"
/**
  * str_concat - concatenates two strings
  * @s1: string 1
  * @s2: string 2
  * Return: Null or Concatenated string
  */
char *str_concat(char *s1, char *s2)
{
	int i;
	int len1 = 0;
	int len2 = 0;
	char *s = (char *) malloc(sizeof(char) * (len1 + len2 + 1));

	if (s1 != NULL)
	{
		len1 = strlen(s1);
	}
	if (s2 != NULL)
	{
		len2 = strlen(s2);
	}

	if (s1 != NULL)
	{
		for (i = 0; s1[i] != '\0'; i++)
		{
			s[i] = s1[i];
		}
	}
	if (s2 != NULL)
	{
		for (i = 0; s2[i] != '\0'; i++)
		{
			s[len1 + i] = s2[i];
		}
	}
	s[len1 + len2] = '\0';
	if (s == NULL)
	{
		return (NULL);
	}
	return (s);
}
