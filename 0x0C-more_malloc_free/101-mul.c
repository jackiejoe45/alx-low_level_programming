#include "main.h"
/**
  * print_number - prints
  * @nums: numbers
  * @len: length
  * Return: none
  */
void print_number(int *nums, int len)
{
	int i, j;

	for (i = len - 1; i >= 0; i--)
	{
		if (nums[i] != 0)
			break;
	}
	if (i < 0)
	{
		_putchar('0');
		_putchar('\n');
		return;
	}
	for (j = i; j >= 0; j--)
	{
		_putchar(nums[j] + '0');
	}
	_putchar('\n');
}
/**
  * parse_number - parses number
  * @str: string arr
  * @nums: numbers
  * @len: length
  * Return: integer
  */
int parse_number(char *str, int *nums, int len)
{
	int i, j, k;

	for (i = 0; i < len; i++)
	{
		nums[i] = 0;
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (-1);
		}
		nums[len - 1 - i] = str[i] - '0';
	}
	return (0);
}
/**
  * add_numbers - adds numbers
  * @num1: number 1
  * @num2: number 2
  * @result: result
  * @len: length
  * Return: none
  */
void add_numbers(int *num1, int *num2, int *result, int len)
{
	int i, carry = 0;

	for (i = 0; i < len; i++)
	{
		result[i] = num1[i] + num2[i] + carry;
		carry = result[i] / 10;
		result[i] %= 10;
	}
}
/**
  * multiply_numbers - multiplies
  * @num1: number 1
  * @num2: number 2
  * @len1: length of 1
  * @len2: length of 2
  * @result: result
  * Return: void
  */
void multiply_numbers(int *num1, int *num2, int len1, int len2, int *result)
{
	int i, j;

	for (i = 0; i < len1 + len2; i++)
	{
		result[i] = 0;
	}
	for (i = 0; i < len1; i++)
	{
		for (j = 0; j < len2; j++)
		{
			result[i + j] += num1[i] * num2[j];
			result[i + j + 1] += result[i + j] / 10;
			result[i + j] %= 10;
		}
	}
}
