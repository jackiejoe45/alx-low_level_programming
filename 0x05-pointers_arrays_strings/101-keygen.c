#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 11
/**
  *main - creates a random password
  *Description: generates random characters
  *Return:Always 0
  */
int main(void)
{
	char password[PASSWORD_LENGTH + 1];
	int i, random_char;

	srand(time(NULL));
	for (i = 0; i < PASSWORD_LENGTH; i++)
	{
		random_char = rand() % ('~' - ' ' + 1) + ' ';
		password[i] = (char)random_char;
	}
	password[PASSWORD_LENGTH] = '\0';
	printf("Generated password: %s\n", password);
	return (0);
}

