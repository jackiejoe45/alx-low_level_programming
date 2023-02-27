#include "main.h"
/**
  * rev_string - reverses a string
  * @s: string to reverse
  * Return : Always 0
  */
void rev_string(char *s)
{
	int len = 0;
	char temp;
	char *end = s;
	int i;

	while (*end != '\0')
	{
		len++;
		end++;
	}
	for (i = 0; i < len / 2; i++)
	{
		temp = *(s + i);
		*(s + i) = *(end - i - 1);
		*(end - i - 1) = temp;
	}
	return (0);
}
