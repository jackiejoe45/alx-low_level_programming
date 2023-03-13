#include "main.h"
/**
  * _strdup - creates a duplicate string in memory
  * @str: string to duplicate
  * Return: duplicted string or Null
  */
char *_strdup(char *str)
{
	int i;
	int len1 = strlen(str);
	char *s = (char *) malloc(sizeof(char) * len1);

	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len1; i++)
	{
		s[i] = str[i];
	}
	return (s);
}
