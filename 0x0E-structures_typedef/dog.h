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
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
