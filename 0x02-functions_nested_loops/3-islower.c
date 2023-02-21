#include "main.h"
/**
 ** _islower-check if character is lowercase.
 * @c:character to check if it islowercase.
 * Return:0-if lowercase,1-if not
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
