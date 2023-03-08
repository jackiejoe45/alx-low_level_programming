#include "main.h"
/**
  * _sqrt_recursion - returns the natural square root of a number.
  * @n: number
  * Return: square root of the number
  */
int _sqrt_recursion(int n)
{
	int prev_sqrt;

	if (n < 0)
	{
		return (-1);
	}
	if (n == 0)
	{
		return (0);
	}

	prev_sqrt = _sqrt_recursion(n / 4);

	if (prev_sqrt * prev_sqrt == n)
	{
		return (prev_sqrt * 2);
	}
	if ((prev_sqrt + 1) * (prev_sqrt + 1) == n)
	{
		return ((prev_sqrt + 1) * 2);
	}
	return (-1);
}
