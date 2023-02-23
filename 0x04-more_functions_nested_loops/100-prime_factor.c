#include <stdio.h>
#include <math.h>
#include "main.h"
/**
 * main - find prime factors
 * Return: Always 0
 */
int main(void)
{
	long long num = 612852475143;
	long long largest_prime_factor = 1;

	while (num % 2 == 0)
	{
		largest_prime_factor = 2;
		num /= 2;
	}
	for (long long i = 3; i <= sqrt(num); i += 2)
	{
		while (num % i == 0)
		{
			largest_prime_factor = i;
			num /= i;
		}
	}
	if (num > 2)
	{
		largest_prime_factor = num;
	}
	printf("%lld\n", largest_prime_factor);
	return (0);
}
