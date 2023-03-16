#include "main.h"
/**
  * is_digit - checks if digit
  * @c: character to check
  * Return: int 0 or 1
  */
int is_digit(char c)
{
  return (c >= '0' && c <= '9');
}
/**
  * print_error - print
  * Return:none
  */
void print_error()
{
	printf("Error\n");
	exit(98);
}

/**
  * parse_number -  parses a number
  * @str: string
  * Return: int
  */
int parse_number(char *str)
{
	int num = 0;
	
	while (*str)
	{
		if (!is_digit(*str))
		{
			print_error();
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}
/**
  * count_digits - counts digits
  * @num: number
  * Return: int
  */
int count_digits(int num)
{
	int count = 0;
	while (num > 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}
/**
  * print_number - prints number
  * @num: number
  * Return: none
  */
void print_number(int num)
{
	if (num == 0)
	{
		_putchar('0');
		return;
	}
	int num_digits = count_digits(num);
	char *str = malloc(num_digits + 1);
	
	if (str == NULL)
	{
		printf("Error: malloc failed\n");
		exit(98);
	}
	str[num_digits] = '\0';
	while (num > 0)
	{
		str[--num_digits] = '0' + (num % 10);
		num /= 10;
	}
	printf("%s", str);
	free(str);
}
/**
  * main - main file
  * @argc: args
  * @argv: kwargs
  * Return: int
  */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		print_error();
	}
	int num1 = parse_number(argv[1]);
	int num2 = parse_number(argv[2]);
	int result = num1 * num2;
	
	print_number(result);
	_putchar('\n');
	return (0);
}
