#include "holberton.h"
/*-----TAKE TO FLAG_ANALYSIS.c*/
char *analyse_code(char *directive_string, formats *formatos, va_list pa, int *directive_length)
{
	int i = 0;

	while (formatos[i].format_specifier)
	{
		if (directive_string[*directive_length] == formatos[i].format_specifier[0])
			return (formatos[i].get_substring(pa));
		i++;
	}
	exit(3);
}

int validate_directive(formats *formatos, char *directive_string, int *flag_number)
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
	exit(4);
}
