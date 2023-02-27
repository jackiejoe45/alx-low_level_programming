 #include "main.h"
/**
 * swap_int - swaps two integers
 * @a: first integer
 * @b: second integer
 * Return:Always 0
 */
void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

	return (0);
}
