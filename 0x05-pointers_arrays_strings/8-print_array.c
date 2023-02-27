#include  "main.h"
/**
  * print_array - prints n elements of a given array
  * @a: array given
  * @n:number of elements
  * Return: Always 0
  */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", *(a + i));
		if (i != n - 1)
		{
			printf(", ");
		}
	}
	printf("\n");
}
