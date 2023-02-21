#include "main.h"
/**
*_abs-prints the absolute value of an integer.
*@n:the integer to compute its absolute value.
*Return:returns the abs value.
*
*/
int _abs(int n)
{
	if (n > 0)
	{
		return (n);
	}
	else
	{
		n = n * -1;
		return (n);
	}
}
