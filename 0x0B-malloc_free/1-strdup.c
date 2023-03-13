#include "main.h"
/**
  * _strdup - creates a duplicate string in memory
  * @str: string to duplicate
  * Return: duplicted string or Null
  */
char *_strdup(char *str)
{
	int i;
	int len1 = 0;
	char *s;

	if (str == NULL)
	{
		return (NULL);
	}

	len1 = strlen(str);
	*s = (char *) malloc(sizeof(char) * (len1 + 1));
	if (s != NULL)
	{
		for (i = 0; i < len1; i++)
		{
			s[i] = str[i];
		}
		s[len1] = '\0';
	}
	return (s);
}
