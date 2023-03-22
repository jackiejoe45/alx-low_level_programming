#include "3-calc.h"
/**
  * op_add - adds two integers
  * @a: integer 1
  * @b: integer 2
  * Return: result(int)
  */
int op_add(int a, int b)
{
	return (a + b);
}
/**
  * op_sub - subtracts two integers
  * @a: integer 1
  * @b: integer 2
  * Return: result(int)
  */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
  * op_mul - multiplies two integers
  * @a: integer 1
  * @b: integer 2
  * Return: result(int)
  */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
  * op_div - divides int 1 by int 2
  * @a: integer 1
  * @b: integer 2
  * Return: result(int)
  */
int op_div(int a, int b)
{
	return (a / b);
}
/**
  * op_mod - return remainder of int 1 / int 2
  * @a: integer 1
  * @b: integer 2
  * Return: result(int)
  */
int op_mod(int a, int b)
{
	return (a - (a / b));
}
