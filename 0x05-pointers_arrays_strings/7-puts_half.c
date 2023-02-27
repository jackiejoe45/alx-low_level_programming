#include "main.h"
/**
  * puts_half - prints the last half of a string
  * @str: string to be put
  * Return: Always 0
  */
void puts_half(char *str)
{
	int len = 0, i;
	char *end = str;

	while (*end != '\0')
	{
		len++;
		end++;
	}
	if (len % 2 == 0)
	{
		for (i = len / 2; i < len; i++)
		{
			_putchar(*(str + i));
		}
	}
	else
	{
		for (i = (len - 1) / 2 + 1; i < len; i++)
		{
			_putchar(*(str + i));
		}
	}
	_putchar('\n');
	return (0);
}

