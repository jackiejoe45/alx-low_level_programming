#include <stdio.h>
#include "main.h"
/*
   *
   *@print_numbers:prints from 0 to 9
   *
   *Return:Always 0
   */
void print_numbers(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		_putcar(i);
	}
	_putchar('\n');
	return (0);
}
