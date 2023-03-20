#ifndef DOG_H
#define DOG_H
#endif /* DOG_H */
/**
 * struct dog - a struct of a dogs basic details
 * @name: name of dog(String)
 * @age: dog's age (integer)
 * @c: name of owner(String)
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;
