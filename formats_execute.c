#include "holberton.h"
/*----TAKE TO FORMATS_EXECUTE.c*/
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
		exit(6);
	c_string[0] = c_char;
	c_string[1] = '\0';
	return (c_string);
}
char *printString(va_list pa)
{
	char *string = va_arg(pa, char *);

	if (string == NULL)
		return ("(null)");
	return (string);
}
char *printIntenger(va_list pa)
{
	char *num_string = NULL;
	int num = va_arg(pa, int);
	int num_length = 0, signo = 0;
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
		exit(1);
	num_string = numberToString(num_string, num, num_length);
	if (signo)
		num_string[0] = '-';
	return (num_string);
}
char *printPercentage(va_list __attribute__((unused)) pa)
{
	return ("%");
}
