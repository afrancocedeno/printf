#include "holberton.h"

/**
 * print - print to stdout
 * @str: string to be printed
 *
 * Return: number of chars
 */
unsigned int print(char *str)
{
	unsigned int string_length = 0;
	/*get final lenght + null char*/
	string_length = get_string_length(str);
	write(1, str, string_length);
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
	va_list pa;        /*list of arguments*/
	char *string = ""; /*string for final result*/
	char *sub_string = "";
	unsigned int i = 0; /*loops iterators*/
	unsigned int buffer_size = 1024;
	unsigned int string_length = 0; /*final lenght of string*/
	formats formatos[6] = {{"%", printPercentage},
			       {"c", printChar},
			       {"s", printString},
			       {"d", printIntenger},
			       {"i", printIntenger},
			       {NULL, NULL}}; /*formats*/
	sub_string = malloc(sizeof(char) * buffer_size);
	if (sub_string == NULL)
		exit(20);
	for (; i < buffer_size; i++)
		sub_string[i] = '\0';
	va_start(pa, format); /*fill list of parameters*/
	/*go through string*/
	i = 0;
	while (*(format + i))
	{
		if (format[i] == '%')
		{
			sub_string = analyse_code(format[i + 1], formatos, pa, sub_string);
			string = sub_string_buffer(sub_string, string);
			i += 2;
			sub_string = reset_sub_buffer(sub_string, buffer_size);
			continue;
		}
		else
			string = buffer(format[i], string); /*send char to buffer*/
		i++;
	}
	string_length = print(string);
	va_end(pa);            /*kill list*/
	if (string[0] != '\0') /*kill string*/
		free(string);
	free(sub_string);
	return (string_length);
}
