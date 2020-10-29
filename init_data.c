#include "holberton.h"

/**
 * init_structure - initialize structure data
 *
 * Return: pointer to structure
 */
formats *init_structure(void)
{
	formats *formatos = NULL;
	int str_array_size = 7;

	formatos = malloc(sizeof(formats) * str_array_size);
	if (formatos == NULL)
		exit(20);

	formatos[0].format_specifier = "%";
	formatos[0].get_substring = printPercentage;
	formatos[1].format_specifier = "c";
	formatos[1].get_substring = printChar;
	formatos[2].format_specifier = "s";
	formatos[2].get_substring = printString;
	formatos[3].format_specifier = "d";
	formatos[3].get_substring = printIntenger;
	formatos[4].format_specifier = "i";
	formatos[4].get_substring = printIntenger;
	formatos[5].format_specifier = "b";
	formatos[5].get_substring = printBinary;
	formatos[6].format_specifier = NULL;
	formatos[6].format_specifier = NULL;

	return (formatos);
}
