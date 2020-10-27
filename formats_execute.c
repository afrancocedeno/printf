#include "holberton.h"

/**
 * printChar - pull char from argmument
 * @pa: variadic function argument
 * @sub_string: return buffer
 *
 * Return: new string of char
 */
char *printChar(va_list pa, char *sub_string)
{
	char c_char;
	int c_num = va_arg(pa, int);

	if (c_num < 0 || c_num > 127)
		exit(5);
	c_char = c_num;
	sub_string[0] = c_char;
	return (sub_string);
}
/**
 * printString - pull string from argmument
 * @pa: variadic function argument
 * @sub_string: return buffer
 *
 * Return: new string
 */
char *printString(va_list pa, char *sub_string)
{
	char *string = va_arg(pa, char *);
	int i = 0;

	if (string == NULL)
	{
		sub_string[0] = '(';
		sub_string[1] = 'n';
		sub_string[2] = 'u';
		sub_string[3] = 'l';
		sub_string[4] = 'l';
		sub_string[5] = ')';
		return (sub_string);
	}
	while (*(string + i))
	{
		sub_string[i] = string[i];
		i++;
	}

	return (sub_string);
}
/**
 * printIntenger - pull int from argmument
 * @pa: variadic function argument
 * @sub_string: return buffer
 *
 * Return: new string of int
 */
char *printIntenger(va_list pa, char *sub_string)
{
	long int num = va_arg(pa, int);
	long int num_length = 0;
	int signo = 0;

	if (num < 0)
	{
		signo = 1;
		num = -num;
		num_length = numberLength(num);
	}
	else
		num_length = numberLength(num);
	sub_string = numberToString(sub_string, num, num_length, signo);
	return (sub_string);
}
/**
 * printPercentage - return percentage
 * @pa: unused argmument
 * @sub_string: return buffer
 *
 * Return: string percetage
 */
char *printPercentage(va_list __attribute__((unused)) pa, char *sub_string)
{
	sub_string[0] = '%';

	return (sub_string);
}
