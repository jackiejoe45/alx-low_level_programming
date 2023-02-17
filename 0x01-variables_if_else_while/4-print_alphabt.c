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
		if (c != 'e' && c != 'q')
		{
			putchar(c);
		}
	}
	putchar('\n');
	return (0);
}

