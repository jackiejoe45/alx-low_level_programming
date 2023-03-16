#include "main.h"
/**
  * string_nconcat - concatenates two strings
  * @s1: String 1
  * @s2: String 2
  * @n: length
  * Return: characters
  */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int len1, len2, len;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	len1 = strlen(s1);
	len2 = strlen(s2);
	if (n >= len2)
	{
		n = len2;
	}
	len = len1 + n;
	concat = malloc(sizeof(char) * (len + 1));
	if (concat == NULL)
	{
		return (NULL);
	}
	memcpy(concat, s1, len1);
	memcpy(concat + len1, s2, n);
	concat[len] = '\0';
	return (concat);
}
