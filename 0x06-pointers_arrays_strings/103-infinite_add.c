#include "main.h"
#include <stdio.h>
/**
  * infinite_add -  adds two numbers
  * @n1: first number
  * @n2: second number
  * @r: array
  * @size_r: size of r
  * Return: char type
  */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int carry = 0, sum = 0;
	int len1 = strlen(n1);
	int len2 = strlen(n2);
	int max_len = (len1 > len2) ? len1 : len2;

	if (max_len + 1 > size_r)
	{
		return (0);
	}
	r[max_len] = '\0';
	for (int i = 0; i < max_len; i++)
	{
		int d1 = (i < len1) ? n1[len1 - i - 1] - '0' : 0;
		int d2 = (i < len2) ? n2[len2 - i - 1] - '0' : 0;

		sum = d1 + d2 + carry;
		carry = sum / 10;
		r[max_len - i] = sum % 10 + '0';
	}
	if (carry == 1)
	{
		r[0] = '1';
		return (&r[0]);
	}
	return (&r[1]);
}
