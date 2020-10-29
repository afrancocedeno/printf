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
	char *(*get_substring)(va_list, char *);
};
typedef struct formats formats;
/*prototypes*/
int _printf(const char *format, ...);
unsigned int get_string_length(char *str);
char *numberToString(char *s, long int n, long int length, int signo);
long int numberLength(long int n);
char *buffer(char c, char *string);
char *printChar(va_list pa, char *string);
char *printString(va_list pa, char *string);
char *printIntenger(va_list pa, char *string);
char *printPercentage(va_list __attribute__((unused)) pa, char *string);
char *printBinary(va_list pa, char *string);
char *analyse_code(char directive_string, formats *formatos,
		   va_list pa, char *string);
unsigned int print(char *str);
formats *init_structure(void);
#endif
