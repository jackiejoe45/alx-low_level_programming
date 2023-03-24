#include "variadic_functions.h"
/**
  * print_numbers - prints numbers passed as arguments
  * @separator:string to be printed between numbers
  * @n: number
  * Return: none
  */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	int i;

	va_start(ap, n);
	for (i = n; i >= 0; i = va_arg(ap, int))
	{
		if (separator == NULL)
		{
			printf("%d", i);
		}
		else
		{
			printf("%d" + *separator, i);
		}
		va_end(ap);
		_putchar('\n');
	}
}
