#include "main.h"
/**
  * malloc_checked - allocate memory using malloc
  * @b: number of bytes to allocate
  * Return: pointer
  */
void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (!ptr)
	{
		printf("Memory allocation failed\n");
		exit(98);
	}
	return (ptr);
}
