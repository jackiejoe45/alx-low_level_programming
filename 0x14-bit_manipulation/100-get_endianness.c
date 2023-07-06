#include "main.h"
/**
 * get_endianness - checks the endianness of the machine
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int n = 1;
	char *p = (char *)&n;

	return (*p == 1);
}

