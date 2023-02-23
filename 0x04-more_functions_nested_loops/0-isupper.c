#include <stdio.h>
/**
  * _isupper - returns wether character is uppercase
  * @c: input charater
  * Return: character status
  */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
		return (0);
}
