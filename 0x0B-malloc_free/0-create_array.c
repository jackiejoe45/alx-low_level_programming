#include "main.h"
/**
  * create_array - creates an array of size and fill with char c
  * @size:size of the array
  * @c:character to fill
  * Return: Null or Array
  */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *arr = (char *) malloc(sizeof(char) * size);

	if(size == 0)
	{
		return (NULL);
	}
	for(i = 0; i <= size; i++)
	{
		arr[i]=c;
	}
	return (arr);
}
