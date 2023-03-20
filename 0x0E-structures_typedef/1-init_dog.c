#include "dog.h"
/**
  * init_dog - creates a dog using the struct dog
  * @d: pointer to dog
  * @name: name of dog
  * @age: dog's age
  * @owner: owner of dog
  * Return: none
  */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
