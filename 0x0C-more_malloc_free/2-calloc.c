#include "main.h"
/**
  * _calloc - allocates memory for an array using malloc
  * @nmemb: number of array elements
  * @size: number of bytes
  * Return: pointer
  */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	memset(ptr, 0, nmemb * size);
	return (ptr);
}
