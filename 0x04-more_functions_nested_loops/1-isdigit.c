#include <stdio.h>
#include "main.h"
/*
   *
   *_isdigit - checks digit stauts of input
   *
   *Return: 1 if true,0 if not
 */
int _isdigit(int c);
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
		return (0);
}
