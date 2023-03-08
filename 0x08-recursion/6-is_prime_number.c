#include "main.h"
/**
  * is_prime_number - checks if a number is prime
  * @n: number
  * Return: 1 if prime) if not prime
  */
int is_prime_number(int n)
{
	int i;

	if (n < 2)
	{
		return (0);
	}

	for (i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			return (0);
		}
	}
	return (1);
}
