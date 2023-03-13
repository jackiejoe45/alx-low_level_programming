#include "main.h"
/**
  * _strdup - creates a duplicate string in memory
  * @str: string to duplicate
  * Return: duplicted string or Null
  */
char *_strdup(char *str)
{
	int i, len1;
	char *s = (char *) malloc(sizeof(char) * len1);

	len1 = strlen(str);
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
