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
char *sub_string_buffer(char *sub_string, char *string);
char *reset_sub_buffer(char *sub_string, unsigned int buffer_size);
char *printChar(va_list pa, char *sub_string);
char *printString(va_list pa, char *sub_string);
char *printIntenger(va_list pa, char *sub_string);
char *printPercentage(va_list __attribute__((unused)) pa, char *sub_string);
char *analyse_code(char directive_string, formats *formatos, va_list pa, char *sub_string);
unsigned int print(char *str);
char *printBinary(va_list pa, char *sub_string);
#endif
