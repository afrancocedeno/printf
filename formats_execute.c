#include "holberton.h"

/**
 * printChar - pull char from argmument
 * @pa: variadic function argument
 * @string: return buffer
 *
 * Return: new string of char
 */
char *printChar(va_list pa, char *string)
{
	char c_char;
	int c_num = va_arg(pa, int);

	if (c_num == 0)
	{
		c_char = c_num;
		string = buffer(c_char, string);
		return (string);
	}

	if (c_num < 0 || c_num > 127)
		exit(5);
	c_char = c_num;
	string = buffer(c_char, string);
	return (string);
}
/**
 * printString - pull string from argmument
 * @pa: variadic function argument
 * @string: return buffer
 *
 * Return: new string
 */
char *printString(va_list pa, char *string)
{
	char *arg_string = va_arg(pa, char *);
	char *null_string = "(null)";
	int i = 0;

	if (arg_string == NULL)
	{
		while (null_string[i])
		{
			string = buffer(null_string[i], string);
			i++;
		}
	}
	else
	{
		i = 0;
		while (*(arg_string + i))
		{
			string = buffer(arg_string[i], string);
			i++;
		}
	}

	return (string);
}
/**
 * printIntenger - pull int from argmument
 * @pa: variadic function argument
 * @string: return buffer
 *
 * Return: new string of int
 */
char *printIntenger(va_list pa, char *string)
{
	long int num = va_arg(pa, int);
	long int num_length = 0;
	int signo = 0, i = 0;
	char *sub_string = NULL;

	if (num < 0)
	{
		signo = 1;
		num = -num;
		num_length = numberLength(num);
		sub_string = malloc(sizeof(char) * num_length + 2);
	}
	else
	{
		num_length = numberLength(num);
		sub_string = malloc(sizeof(char) * num_length + 1);
	}

	sub_string = numberToString(sub_string, num, num_length, signo);
	if (signo == 1)
		num_length += 1;
	sub_string[num_length] = '\0';

	while (sub_string[i])
	{
		string = buffer(sub_string[i], string);
		i++;
	}
	free(sub_string);
	return (string);
}
/**
 * printPercentage - return percentage
 * @pa: unused argmument
 * @string: return buffer
 *
 * Return: string percetage
 */
char *printPercentage(va_list __attribute__((unused)) pa, char *string)
{
	string = buffer('%', string);

	return (string);
}
/**
 * printBinary - pull int from argmument
 * @pa: variadic function argument
 * @string: return buffer
 *
 * Return: new string of binary
 */
char *printBinary(va_list pa, char *string)
{
	int num, i;
	int *binary = NULL;
	int mem_binary = 1024;

	num = va_arg(pa, int);
	if (num < 0)
		num = -num;
	binary = malloc(sizeof(int) * mem_binary);
	for (i = 0; num > 0; i++)
	{
		binary[i] = num % 2;
		num = num / 2;
	}
	for (i = i - 1; i >= 0; i--)
	{
		string = buffer(binary[i] + '0', string);
	}
	free(binary);
	return (string);
}
