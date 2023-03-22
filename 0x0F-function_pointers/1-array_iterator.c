#include "function_pointers.h"
/**
  * array_iterator - executes a given function  on each element of an array.
  * @array: pointer to array
  * @size: size of array
  * @action:pointer to the function used
  */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned long int i;


	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
