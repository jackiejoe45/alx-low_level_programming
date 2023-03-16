#include "main.h"
/**
  * array_range - creates an array of integers
  * @min: minimum
  * @max: maximum
  * Return: Array
  */
int *array_range(int min, int max)
{
	int *arr, i;

	if (min > max)
	{
		return (NULL);
	}
	arr = malloc((max - min + 1) * sizeof(int));
	if (!arr)
	{
		return (NULL);
	}
	for (i = 0; i <= max - min; i++)
	{
		arr[i] = min + i;
	}
	return (arr);
}
