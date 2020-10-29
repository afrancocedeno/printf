#include "holberton.h"

/**
 * analyse_code - analyse format of printf
 * @directive_string: code of format
 * @formatos: all the code formats
 * @pa: list of arguments
 * @string: return buffer
 *
 * Return: string percetage
 */
char *analyse_code(char directive_string, formats *formatos, va_list pa,
		   char *string)
{
	int i = 0;

	while (formatos[i].format_specifier)
	{
		if (directive_string == formatos[i].format_specifier[0])
		{
			string = formatos[i].get_substring(pa, string);
			return (string);
		}
		i++;
	}
	string = buffer('%', string);
	string = buffer(directive_string, string);
	return (string);
}
