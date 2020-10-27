#include "holberton.h"

/**
 * analyse_code - analyse format of printf
 * @directive_string: code of format
 * @formatos: all the code formats
 * @pa: list of arguments
 * @sub_string: return buffer
 *
 * Return: string percetage
 */
char *analyse_code(char directive_string, formats *formatos,
		   va_list pa, char *sub_string)
{
	int i = 0;

	while (formatos[i].format_specifier)
	{
		if (directive_string == formatos[i].format_specifier[0])
		{
			sub_string = formatos[i].get_substring(pa, sub_string);
			return (sub_string);
		}
		i++;
	}
	sub_string[0] = '%';
	sub_string[1] = directive_string;
	return (sub_string);
}
