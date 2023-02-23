#include <stdio.h>
#include "main.h"
/*
   *@print_line:print a line of n length
   *
   *Return :Always 0
   */
void print_line(int n)
{
	int i;

	if (n <= 0)
	{
		for (i = 0; i < n; i++)
		{
			_putchar('_');
		}
		_putchar('\n');
	}
	else
		_putchar('\n');
	return (0);
}
