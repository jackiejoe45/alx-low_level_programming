#include "variadic_functions.h"
/**
  * sum_them_all - sums all arguments provided
  * @n: argument
  * Return: sum of arguments
  */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	int i, sum = 0;
	
	va_start(ap, n);
        if (n == 0)
        {
                return (0);
        }
        for (i = n; i > 0; i--)
        {
                sum += va_arg(ap, int);
        }
	return (sum);
}
