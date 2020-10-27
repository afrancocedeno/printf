#include "holberton.h"

/**
 * printChar - pull char from argmument
 * @pa: variadic function argument
 *
 * Return: new string of char
 */
char *printChar(va_list pa)
{
	char c_char;
	char *c_string = NULL;
	int c_num = va_arg(pa, int);

	if (c_num < 0 || c_num > 127)
		exit(5);
	c_char = c_num;
	c_string = malloc(sizeof(*c_string) * 2);
	if (c_string == NULL)
		return(1);
	c_string[0] = c_char;
	c_string[1] = '\0';
	return (c_string);
}
/**
 * printString - pull string from argmument
 * @pa: variadic function argument
 *
 * Return: new string
 */
char *printString(va_list pa)
{
	char *string = va_arg(pa, char *);

	if (string == NULL)
		return ("(null)");
	return (string);
}
/**
 * printIntenger - pull int from argmument
 * @pa: variadic function argument
 *
 * Return: new string of int
 */
char *printIntenger(va_list pa)
{
	char *num_string = NULL;
	int num = va_arg(pa, int);
	int num_length = 0, signo = 0, i = 0;

	if (num < 0)
	{
		signo = 1;
		num *= -1;
		num_length = numberLength(num) + 1;
	}
	else
		num_length = numberLength(num);
	num_string = malloc(sizeof(*num_string) * num_length + 1);
	if (num_string == NULL)
		return(1);
	for (; i <= num_length; i++)
		num_string[i] = '\0';
	num_string = numberToString(num_string, num, num_length, signo);
	return (num_string);
}
/**
 * printPercentage - return percentage
 * @pa: unused argmument
 *
 * Return: string percetage
 */
char *printPercentage(va_list __attribute__((unused)) pa)
{
	return ("%");
}
