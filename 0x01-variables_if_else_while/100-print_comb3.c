#include <stdio.h>
/**
 * main - Entry point
 * Description:
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j;

	for (i = 0; i < 9; i++)
	{
		for (j = i + 1; j <= 9; j++)
		{
			putchar('0' + i);
			putchar('0' + j);
			if (i < 8 || j < 9)
			{ /* do not print the last comma and space*/
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
