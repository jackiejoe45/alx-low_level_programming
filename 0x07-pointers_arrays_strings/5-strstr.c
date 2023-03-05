#include "main.h"
/**
  * _strstr - locates a substring
  * @haystack: string to be searched
  * @needle: substring to search for
  * Return: haystack or null
  */
char *_strstr(char *haystack, char *needle)
{
	int needle_len = strlen(needle);


	if (needle_len == 0)
	{
		return (haystack);
	}
	while (*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			if (strncmp(haystack, needle, needle_len) == 0)
			{
				return (haystack);
			}
		}
		haystack++;
	}
	return (NULL);
}
