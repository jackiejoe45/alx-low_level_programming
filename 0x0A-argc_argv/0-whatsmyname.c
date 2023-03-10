#include <stdio.h>
/**
  * main - prints its name
  * @argc: arguments
  * @argv: arguments
  * Return: Always 0 (Success)
  */
int main(int argc, char *argv[])
{
	int i;
	
	for (i = 0; i < argc; i++)
	{
		printf("Argument %d: %s\n", i, argv[i]);
	}
	return (0);
}
