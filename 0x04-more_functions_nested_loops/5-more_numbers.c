#include <stdio.h>
/*
   *@more_numbers : print 0 -14 ten times
   *
   *Retun :Always 0
   */
void more_numbers(void);
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 15; j++)
		{
			_putchar(i);
		}
		putchar('\n')
	}
	return (0);
}
