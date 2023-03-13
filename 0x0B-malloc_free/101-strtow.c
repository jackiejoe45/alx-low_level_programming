#include "main.h"
/**
  * count_words - count the number of words in the string
  * @str: string to count
  * Return: word count
  */
int count_words(char *str)
{
	int count = 0;
	int in_word = 0;

	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
		{
			in_word = 0;
		}
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}
/**
 * strtow - breaks a string into words
 * @str:string to breakdown
 * Return: char
 */
char **strtow(char *str)
{
	char **words;
	int word_count = 0;
	char *word;
	char *saveptr;
	int i = 0;

	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}
	word_count = count_words(str);
	words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
	{
		return (NULL);
	}

	word = strtok_r(str, DELIM, &saveptr);
	while (word != NULL)
	{
		words[i] = strdup(word);
		if (words[i] == NULL)
		{
			return (NULL);
		}
		i++;
		word = strtok_r(NULL, DELIM, &saveptr);
	}
	words[i] = NULL;
	return (words);
}
