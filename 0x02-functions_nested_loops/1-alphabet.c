#include "main.h"
#include "main.h"
/**
* print_alphabet - prints all alphabets in lowercase.
* Return: On success 1.
*/
void print_alphabet(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
	{
		putchar(i);
	}
	putchar('\n');
}
