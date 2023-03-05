#include "main.h"
/**
  * print_diagsums - prints the sum of the two diagonals of a square matrix
  * @a: 1D array
  * @size: size of matrix
  */
void print_diagsums(int *a, int size)
{
	int i, sum1 = 0, sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += *(a + i * size + i);
		sum2 += *(a + i * size + size - i - 1);
	}
	printf("Sum of diagonal from top-left to bottom-right: %d\n", sum1);
	printf("Sum of diagonal from top-right to bottom-left: %d\n", sum2);
}
