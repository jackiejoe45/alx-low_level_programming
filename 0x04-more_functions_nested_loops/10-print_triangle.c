#include <stdio.h>
#include "main.h"
/**
 * print_line - print a line of n length
 * @n: parameter
 * Return :Always 0
 */
void print_line(int n)
{
	int i, j, k;

	k = n - 1;
	if (n >= 0)
	{
		for (i = 0; i < n ; i++)
		{
			for (j = k ; j > i ; j--)
			{
				_putchar(' ');
			}
			_putchar('#');
		}
		_putchar('\n');
	}
	else
		print('\n');
	return (0);
}
