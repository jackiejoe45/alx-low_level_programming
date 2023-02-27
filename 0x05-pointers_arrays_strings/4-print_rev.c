#include "main.h"
/**
  * print_rev - prints a string in reverse
  * @s: string to be reversed
  * Return: Always 0
  */
void print_rev(char *s)
{
	int len = 0, i;
	char *p = s;

	while (*p != '\0')
	{
		len++;
		p++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		_putchar(*(s + i));
	}
	_putchar('\n');
}
