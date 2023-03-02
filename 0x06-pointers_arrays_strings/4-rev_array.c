#include "main.h"
#include <stdio.h>
/**
  * reverse_array - reverses the content of an array
  * @a: array
  * @n: number of elements
  */
void reverse_array(int *a, int n)
{
	int i = 0, j = n - 1, temp;

	while (i < j)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		i++;
		j--;
	}
}
