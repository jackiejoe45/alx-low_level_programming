#include <stdlib.h>
#include <stdio.h>
/**
 * main - Entry point
 * Description:
 * Return: Always 0 (Success)
 */
int main(void)
{
	for (char c = 'z' ; c >= 'a'; c--)
	{
		putchar(c);
	}
	putchar('\n');
	return (0);
}
