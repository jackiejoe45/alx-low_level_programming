#include "hash_tables.h"
/**
 * hash_djb2 - Hash function implementing djb2 algorithm.
 * @str: The string to hash.
 * Return: calculated hash.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int count;

	hash = 5381;
	while ((count = *str++))
		hash = ((hash << 5) + hash) + count;
	return (hash);
}
