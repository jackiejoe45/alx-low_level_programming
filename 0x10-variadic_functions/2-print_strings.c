#include "variadic_functions.h"
/**
  * print_strings - prints string passed as arguments
  * @separator:string to be printed between strings
  * @n: number of strings
  * Return: none
  */
void print_strings(const char *separator, const unsigned int n, ...)
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
			if (i != NULL)
			{
				printf("(nil)" + *separator, i);
			}
			printf("%d" + *separator, i);
		}
		va_end(ap);
		_putchar('\n');
	}
}
