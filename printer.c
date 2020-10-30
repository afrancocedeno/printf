#include "holberton.h"

/**
 * print - print to stdout
 * @string: string to be printed
 *
 * Return: number of chars
 */
unsigned int print(char *string)
{
	unsigned int string_length = 0;
	/*get final lenght + null char*/
	string_length = get_string_length(string);
	write(1, string, string_length);

	return (string_length);
}

/**
 * _printf - print string according to format
 * @format: string to be printed with arguments
 *
 * Return: number of chars
 */
int _printf(const char *format, ...)
{
	va_list pa;                     /*list of arguments*/
	char *string = "";              /*string for final result*/
	unsigned int i = 0;             /*loops iterators*/
	unsigned int string_length = 0; /*final lenth*/
	formats *formatos = NULL;       /*formats specifications*/

	/*initial checks*/
	if (format == NULL || format[0] == '\0' ||
	    (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(pa, format); /*fill list of parameters*/
	formatos = init_structure();
	i = 0;
	while (*(format + i))
	{
		if (format[i] == '%')
		{
			string = analyse_code(format[i + 1], formatos, pa, string);
			i += 2;
			continue;
		}
		else
			string = buffer(format[i], string);
		i++;
	}

	string_length = print(string);
	if (string[0] == '\0' && string[1] == '\0')
		string_length += 1;
	/*kill them all*/
	va_end(pa);
	if (string[0] != '\0')
		free(string);
	free(formatos);
	return (string_length);
}
