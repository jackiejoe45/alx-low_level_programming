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
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			in_word = 0;
		}
		else if (in_word == 0)
		{
			count++;
			in_word = 1;
		}
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
	int num_words;
	char **words;
	int word_start;
	int word_end;
	int word_index;
	int in_word;
	int i, j;

	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}

	num_words = count_words(str);
	words = malloc((num_words + 1) * sizeof(char *));

	if (words == NULL)
	{
		return (NULL);
	}
	word_start = -1;
	word_end = -1;
	word_index = 0;
	in_word = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			if (in_word)
			{
				word_end = i - 1;
				words[word_index] = malloc((word_end - word_start + 2) * sizeof(char));
				if (words[word_index] == NULL)
				{
					for (j = 0; j < word_index; j++)
					{
						free(words[j]);
					}
					free(words);
					return (NULL);
				}
				strncpy(words[word_index], &str[word_start], word_end - word_start + 1);
				words[word_index][word_end - word_start + 1] = '\0';
				word_index++;
				in_word = 0;
			}
		}
		else
		{
			if (!in_word)
			{
				word_start = i;
				in_word = 1;
			}
		}
	}
	if (in_word)
	{
		word_end = strlen(str) - 1;
		words[word_index] = malloc((word_end - word_start + 2) * sizeof(char));
		if (words[word_index] == NULL)
		{
			for (j = 0; j < word_index; j++)
			{
				free(words[j]);
			}
			free(words);
			return (NULL);
		}
		strncpy(words[word_index], &str[word_start], word_end - word_start + 1);
		words[word_index][word_end - word_start + 1] = '\0';
		word_index++;
	}
	if (in_word)
	{
		word_end = strlen(str) - 1;
		words[word_index] = malloc((word_end - word_start + 2) * sizeof(char));
		if (words[word_index] == NULL)
		{
			for (j = 0; j < word_index; j++)
			{
				free(words[j]);
			}
			free(words);
			return (NULL);
		}
		strncpy(words[word_index], &str[word_start], word_end - word_start + 1);
		words[word_index][word_end - word_start + 1] = '\0';
		word_index++;
	}
	words[word_index] = NULL;
	return (words);
}
