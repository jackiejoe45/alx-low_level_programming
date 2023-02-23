#include <stdio.h>
#include "main.h"
/*
   *
   *_isdigit - checks digit stauts of input
   *
   *Return: 1 if true,0 if not
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		_putchar('\n');
		return (1);
	}
	else
	{
		_putchar('\n');
		return (0);
	}
}
