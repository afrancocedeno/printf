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
	va_list pa;
	char *string = "", *sub_string = "";
	unsigned int i = 0, string_length = 0;
	int j, flag_number = 5, directive_length = 0;
	formats formatos[6] = {{"c", printChar}, {"s", printString},
			       {"d", printIntenger}, {"i", printIntenger},
			       {"%", printPercentage}, {NULL, NULL}};
	char directive_string[6];

	va_start(pa, format); /*fill list of parameters*/
	while (*(format + i))
	{
		if (format[i] == '%')
		{
			for (j = 0; j < flag_number; j++)
			{
				if (format[(i + 1) + j] != '\0')
					directive_string[j] = format[(i + 1) + j];
				else
					directive_string[j] = '\0';
			}
			directive_string[j] = '\0';
			directive_length = validate_directive(formatos,
							      directive_string, &flag_number);
			sub_string = analyse_code(directive_string, formatos,
						  pa, &directive_length);
			string = sub_string_buffer(sub_string, string);
			i += 2 + directive_length; /*2 represents acutal % position*/
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
	return (string_length);
}
