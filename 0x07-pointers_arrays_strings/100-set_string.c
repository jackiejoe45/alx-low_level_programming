#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * set_string - sets the value of a pointer to a char
 * @s: character
 * @to: point of memory location
 */
void set_string(char **s, char *to)
{
	int len = strlen(to);
	*s = (char *) malloc(len+1);
	strcpy(*s, to);
}
