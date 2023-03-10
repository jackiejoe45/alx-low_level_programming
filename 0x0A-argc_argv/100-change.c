#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints minimum number of coins to make change for an amount of money
 * @argc: number of arguments passed to the program
 * @argv: array of arguments passed to the program
 * Return: 0 if successful, 1 otherwise
 */
int main(int argc, char *argv[])
{
	int coins[] = {25, 10, 5, 2, 1};
	int total_coins = 0, cents, i;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}
	for (i = 0; i < 5 && cents > 0; i++)
	{
		total_coins += cents / coins[i];
		cents %= coins[i];
	}
	printf("%d\n", total_coins);
	return (0);
}
