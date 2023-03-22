#include "function_pointers.h"
/**
  * print_name - prints a name
  * @name: name to print
  * @f: function to use
  * Return: none
  */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
