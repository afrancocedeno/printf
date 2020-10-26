#ifndef __HOLBERTON_H__
#define __HOLBERTON_H__
/*------TAKE TO HOLBERTON.H*/
/*includes*/
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
/*structures*/
typedef struct formats
{
	char *format_specifier;
	char *(*get_substring)(va_list);
} formats;
/*prototypes*/
/*buffer.c ptypos*/
char *buffer(char c, char *string);
char *sub_string_buffer(char *sub_string, char *string);
/*flag_analysis.c ptypos*/
char *analyse_code(char *directive_string, formats *formatos, va_list pa, int *directive_length);
int validate_directive(formats *formatos, char *directive_string, int *flag_number);
/*formats_execute.c ptypos*/
char *printChar(va_list pa);
char *printString(va_list pa);
char *printIntenger(va_list pa);
char *printPercentage(va_list __attribute__((unused)) pa);
/*helper_functions ptypos*/
unsigned int get_string_length(char *str);
char *numberToString(char *s, int n, int length);
int numberLength(int n);
/*printer.c ptypos*/
unsigned int print(char *str);
int _printf(const char *format, ...);
#endif
