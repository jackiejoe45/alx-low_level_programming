#include <stdio.h>
#include "main.h"
/**
 * main - prints from 1 to 100,Fizz instead of multiples of 3
 *, buzz instead of multiples of 5 and FizzBuzz instead of
 *  multiples of both 3 and 5
 *
 * Return: Always 0
 */
int main(void)
{
	int i;

	for (i = 1; i < 101 ; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			printf("FizzBuzz");
		}
		else if (i % 3 == 0)
		{
			printf("Fizz")
		}
		else if (i % 5 == 0)
		{
			printf("Buzz")
		}
		else
		{
			printf("%d", i)
		}
	}
	return (0);
}

