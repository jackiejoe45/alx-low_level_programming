#include "main.h"
/**
* _isalpha-check if character is lowercase or uppercase
* @c:character to check if it islowercase.
* Return:1-if lowercase/uppercase,0-if not.
*/
int _isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (0);
	}

	else if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (1);
	}
}
