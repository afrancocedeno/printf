#include "holberton.h"

/**
 * analyse_code - analyse format of printf
 * @directive_string: code of format
 * @formatos: all the code formats
 * @pa: list of arguments
 * @directive_length: length of code
 *
 * Return: string percetage
 */
char *analyse_code(char *directive_string, formats *formatos,
		   va_list pa, int *directive_length)
{
	int i = 0;

	while (formatos[i].format_specifier)
	{
		if (directive_string[*directive_length] == formatos[i].format_specifier[0])
			return (formatos[i].get_substring(pa));
		i++;
	}
	return ("%k");
}
/**
 * validate_directive - validate code directive
 * @directive_string: code of format
 * @formatos: all the code formats
 * @flag_number: number of possible flags
 *
 * Return: string percetage
 */
int validate_directive(formats *formatos, char *directive_string,
		       int *flag_number)
{
	int length = 0, i = 0, j = 0;
	/*i < maximun number of flags*/
	while (i < *flag_number)
	{
		while (formatos[i].format_specifier)
		{
			if (directive_string[i] == formatos[i].format_specifier[j])
			{
				return (length);
			}
			j++;
		}
		i++;
		length++;
	}
	/*if not format found*/
	exit(1);
}
