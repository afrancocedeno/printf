#include <stdio.h> /*THIS GOES IN MAIN*/
#include <limits.h>
/*------TAKE TO HOLBERTON.H*/
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

/*---- TAKE TO HELPER_FUNCTIONS.c*/
/**
 * get_string_length - return string length
 * @str: string
 *
 * Return: length of string whitout null
 */
unsigned int get_string_length(char *str)
{
	unsigned int length = 0;

	while (*(str + length))
		length++;
	return (length);
}

/**
 * numberToString - turn number into string
 * @s: pointer to memory blocks to allocate number
 * @n: number to be stored as a string
 * @length: digits of the number
 *
 * Return: number as a string
 */
char *numberToString(char *s, long int n, long int length, int signo)
{
	while (length > 0)
	{
		if (signo == 1)
			s[length] = (n % 10) + '0';
		else
			s[length - 1] = (n % 10) + '0';
		n /= 10;
		length--;
	}
	if (signo == 1)
		s[0] = '-';
	return (s);
}

/**
 * numberLength - gets number of digits
 * @n: number
 *
 * Return: number of digits
 */
long int numberLength(long int n)
{
	int c = 1;

	while (n > 9)
	{
		n /= 10;
		c++;
	}
	return (c);
}

/*-----TAKE TO BUFFER.c*/
/**
 * buffer - push char and return new string
 * @c: char to push
 * @string: string to add char
 *
 * Return: new string
 */
char *buffer(char c, char *string)
{
	char *new_str = NULL;
	unsigned int string_length = 0;
	unsigned int i = 0;

	string_length = get_string_length(string);
	/*allocate memory for new char + null character*/
	new_str = malloc(sizeof(char) * (string_length + 2));
	if (new_str == NULL)
	{
		if (string_length > 1)
			free(string);
		exit(1);
	}
	/*str to new_str*/
	for (; i < string_length; i++)
		new_str[i] = string[i];
	/*new char to new_str*/
	new_str[i] = c;
	new_str[i + 1] = '\0';
	if (string[0] != '\0') /*kill string*/
		free(string);
	return (new_str);
}
/**
 * sub_string_buffer - push string and return new string
 * @sub_string: string to push
 * @string: string to add sub_string
 *
* Return: new string
 */
char *sub_string_buffer(char *sub_string, char *string)
{
	char *new_str = NULL;
	unsigned int string_length = 0;
	unsigned int new_string_length = 0;
	unsigned int i = 0, j;

	string_length = get_string_length(string);
	new_string_length = (string_length + get_string_length(sub_string) + 1);
	/*allocate memory for new char + null character*/
	new_str = malloc(sizeof(char) * new_string_length);
	if (new_str == NULL)
	{
		if (string_length > 1)
			free(string);
		exit(2);
	}
	/*string to new_str*/
	for (; i < string_length; i++)
		new_str[i] = string[i];
	/*sub_string to new_str*/
	for (j = 0; i + j < new_string_length - 1; j++)
		new_str[i + j] = sub_string[j];
	new_str[i + j] = '\0';
	if (string[0] != '\0') /*kill string*/
		free(string);
	return (new_str);
}
/**
 * reset_sub_buffer - fill string with \0
 * @sub_string: string to fill
 * @buffer_size: size of string
 *
 * Return: new string
 */
char *reset_sub_buffer(char *sub_string, unsigned int buffer_size)
{
	unsigned int i = 0;

	for (; i < buffer_size; i++)
		sub_string[i] = '\0';
	return (sub_string);
}

/*----TAKE TO FORMATS_EXECUTE.c*/
/**
 * printChar - pull char from argmument
 * @pa: variadic function argument
 * @sub_string: return buffer
 *
 * Return: new string of char
 */
char *printChar(va_list pa, char *sub_string)
{
	char c_char;
	int c_num = va_arg(pa, int);

	if (c_num < 0 || c_num > 127)
		exit(5);
	c_char = c_num;
	sub_string[0] = c_char;
	return (sub_string);
}
/**
 * printString - pull string from argmument
 * @pa: variadic function argument
 * @sub_string: return buffer
 *
 * Return: new string
 */
char *printString(va_list pa, char *sub_string)
{
	char *string = va_arg(pa, char *);
	int i = 0;

	if (string == NULL)
	{
		sub_string[0] = '(';
		sub_string[1] = 'n';
		sub_string[2] = 'u';
		sub_string[3] = 'l';
		sub_string[4] = 'l';
		sub_string[5] = ')';
		return (sub_string);
	}
	while (*(string + i))
	{
		sub_string[i] = string[i];
		i++;
	}

	return (sub_string);
}
/**
 * printIntenger - pull int from argmument
 * @pa: variadic function argument
 * @sub_string: return buffer
 *
 * Return: new string of int
 */
char *printIntenger(va_list pa, char *sub_string)
{
	long int num = va_arg(pa, int);
	long int num_length = 0;
	int signo = 0;

	if (num < 0)
	{
		signo = 1;
		num = -num;
		num_length = numberLength(num);
	}
	else
		num_length = numberLength(num);
	sub_string = numberToString(sub_string, num, num_length, signo);
	return (sub_string);
}
/**
 * printPercentage - return percentage
 * @pa: unused argmument
 * @sub_string: return buffer
 *
 * Return: string percetage
 */
char *printPercentage(va_list __attribute__((unused)) pa, char *sub_string)
{
	sub_string[0] = '%';

	return (sub_string);
}
/**
 * printBinary - pull int from argmument
 * @pa: variadic function argument
 * @sub_string: return buffer
 *
 * Return: new string of binary
 */
char *printBinary(va_list pa, char *sub_string)
{
	int a[10], n, i;

	n = va_arg(pa, int);
	for (i = 0; n > 0; i++)
	{
		a[i] = n % 2;
		n = n / 2;
	}
	for (i = i - 1; i >= 0; i--)
	{
		sub_string[i] = a[i];
	}
	return (sub_string);
}

/*-----TAKE TO FLAG_ANALYSIS.c*/
/**
 * analyse_code - analyse format of printf
 * @directive_string: code of format
 * @formatos: all the code formats
 * @pa: list of arguments
 * @directive_length: length of code
 * @sub_string: return buffer
 *
 * Return: string percetage
 */
char *analyse_code(char directive_string, formats *formatos, va_list pa, char *sub_string)
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

/*----TAKE TO PRINTER.c*/
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
	va_list pa;        /*list of arguments*/
	char *string = ""; /*string for final result*/
	char *sub_string = NULL;
	unsigned int i = 0; /*loops iterators*/
	unsigned int buffer_size = 1024;
	unsigned int string_length = 0;
	formats formatos[7] = {{"%", printPercentage}, {"c", printChar}, {"s", printString}, {"d", printIntenger}, {"i", printIntenger}, {"b", printBinary}, {NULL, NULL}}; /*formats*/
	sub_string = malloc(sizeof(char) * buffer_size);
	if (sub_string == NULL)
		exit(20);
	for (; i < buffer_size; i++)
		sub_string[i] = '\0';
	va_start(pa, format); /*fill list of parameters*/
	if ((format[0] == '%' && format[1] == '\0') || !format)
		return (0);
	i = 0;
	while (*(format + i))
	{
		if (format[i] == '%')
		{
			sub_string = analyse_code(format[i + 1], formatos, pa, sub_string);
			string = sub_string_buffer(sub_string, string);
			i += 2;
			sub_string = reset_sub_buffer(sub_string, buffer_size);
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
	free(sub_string);
	return (string_length);
}

/*----TAKE TO MAIN.c*/
int main()
{
	_printf("Binario de 5: %b", 5);
	return (0);
}
