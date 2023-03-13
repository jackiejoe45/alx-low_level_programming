#include "main.h"
/**
  * alloc_grid - creates a grid in memory
  * @width: width of grid
  * @height: height of grid
  * Return: Null or Grid
  */
int **alloc_grid(int width, int height)
{
	int i, j;
	int **arr = (int **) malloc(height * sizeof(int *));

	for (i = 0; i < height; i++)
	{
		arr[i] = (int *) malloc(width * sizeof(int));
	}
	if (width <= 0)
	{
		return (NULL);
	}
	if (height <= 0)
	{
		return (NULL);
	}
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			arr[i][j] = 0;
		}
	}
	return (arr);
}
