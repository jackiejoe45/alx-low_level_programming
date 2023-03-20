#include "dog.h"
/**
  * free_dog - frees a dog from memory
  * @d:dog pointer
  * Return: none
  */
void free_dog(dog_t *d)
{
	if (d == NULL)
	{
		return;
	}
	free(d->name);
	free(d->owner);
	free(d);
}
