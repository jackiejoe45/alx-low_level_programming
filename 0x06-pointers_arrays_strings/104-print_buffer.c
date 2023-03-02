#include "main.h"
#include <stdio.h>
#include <ctype.h>
/**
  * print_buffer - prints a buffer
  * @b: buffer
  * @size: size of buffer
  * Return: void
  */
void print_buffer(char *b, int size)
{
	int i, j;
	unsigned char c;

	for (i = 0; i < size; i += 10)
	{
		printf("%08x ", i);
		for (j = i; j < i + 10; j++)
		{
			if (j < size)
			{
				printf("%02x ", (unsigned char)b[j]);
			}
			else
			{
				printf("   ");
			}
		}
		printf(" ");
		for (j = i; j < i + 10; j++)
		{
			if (j < size)
			{
				c = b[j];
				if (!isprint(c))
				{
					c = '.';
				}
				printf("%c", c);
			}
		}
		printf("\n");
	}
	if (size <= 0)
	{
		printf("\n");
	}
}
