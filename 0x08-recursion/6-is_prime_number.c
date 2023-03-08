#include "main.h"

/**
 * is_prime_recursive - checks if a number is prime recursively
 * @n: number to check
 * @i: iterator
 * Return: 1 if prime, 0 if not prime
 */
int is_prime_recursive(int n, int i)
{
	if (n < 2)
	{
		return (0);
	}
	if (i == 1)
	{
		return (1);
	}
	if (n % i == 0)
	{
		return (0);
	}
	return (is_prime_recursive(n, i - 1));
}
/**
 * is_prime_number - checks if a number is prime
 * @n: number to check
 * Return: 1 if prime, 0 if not prime
 */
int is_prime_number(int n)
{
	return (is_prime_recursive(n, n / 2));
}
