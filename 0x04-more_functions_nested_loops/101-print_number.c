#include <stdio.h>
#include "main.h"
/**
 * print_number - prints an integer
 * @n: number to be converted
 * Return: Always 0
 */
void print_number(int n)
{
	int divisor, digit;

	if (n == 0)
	{
		_putchar('0');
	}
	else
	{
		if (n < 0)
		{
			_putchar('-');
			n *= -1;
		}
	}
	divisor = 1;
	while (n / divisor >= 10)
	{
		divisor *= 10;
		while (divisor >= 1)
		{
			digit = n / divisor;
			n = n % divisor;
			divisor /= 10;
			_putchar(digit + '0');
		}
	}
}
