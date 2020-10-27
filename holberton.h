#ifndef __HOLBERTON__H__
#define __HOLBERTON__H__
/*includes*/
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
/*structures*/
/**
 * struct formats- format code and functions
 * @format_specifier: format_specifier
 * @get_substring: function pointer to get substring
 *
 * Description: data to evaluate how to print
 */
struct formats
{
	char *format_specifier;
	char *(*get_substring)(va_list);
};
/*typedef*/
typedef struct formats formats;
/*prototypes*/
int _printf(const char *format, ...);
unsigned int print(char *str);
int validate_directive(formats *formatos, char *directive_string,
		       int *flag_number);
char *analyse_code(char *directive_string, formats *formatos,
		   va_list pa, int *directive_length);
char *printPercentage(va_list __attribute__((unused)) pa);
char *printIntenger(va_list pa);
char *printString(va_list pa);
char *printChar(va_list pa);
char *sub_string_buffer(char *sub_string, char *string);
char *buffer(char c, char *string);
int numberLength(int n);
char *numberToString(char *s, int n, int length, int signo);
unsigned int get_string_length(char *str);
#endif
