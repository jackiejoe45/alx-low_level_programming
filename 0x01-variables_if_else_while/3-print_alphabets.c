#include <stdlib.h>
#include <stdio.h>

/**
 * main - Entry point
 * Description:
 * Return: Always 0 (Success)
 */
int main(void)
{
	for (char c = 'a'; c <= 'z'; c++)
	{
		putchar(c);
	}

	for (char c = 'A'; c <= 'Z'; c++)
	{
		/* main-print the alphabet*/
		putchar(c);
	}
	putchar("\n");
	return (0);
}
