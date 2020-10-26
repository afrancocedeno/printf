#include <stdio.h> /*THIS GOES IN MAIN*/

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
int _printf(const char *format, ...);

/*---- TAKE TO HELPER_FUNCTIONS.c*/
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
char *numberToString(char *s, int n, int length)
{
	int initial_length = length;
	while (length >= 0)
	{
		s[length - 1] = (n % 10) + '0';
		n /= 10;
		length--;
	}
	s[initial_length] = '\0';
	return (s);
}

/**
 * numberLength - gets number of digits
 * @n: number
 *
 * Return: number of digits
 */
int numberLength(int n)
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
	for (j = 0; i + j < new_string_length; j++)
		new_str[i + j] = sub_string[j];
	new_str[i + j] = '\0';
	if (string[0] != '\0') /*kill string*/
		free(string);
	return (new_str);
}

/*----TAKE TO FORMATS_EXECUTE.c*/
char *printChar(va_list pa)
{
	char c_char;
	char *c_string = NULL;
	int c_num = va_arg(pa, int);

	if (c_num < 0 || c_num > 127)
		exit(5);
	c_char = c_num;
	c_string = malloc(sizeof(*c_string) * 2);
	if (c_string == NULL)
		exit(6);
	c_string[0] = c_char;
	c_string[1] = '\0';
	return (c_string);
}
char *printString(va_list pa)
{
	char *string = va_arg(pa, char *);

	if (string == NULL)
		return ("(null)");
	return (string);
}
char *printIntenger(va_list pa)
{
	char *num_string = NULL;
	int num = va_arg(pa, int);
	int num_length = 0, signo = 0;
	if (num < 0)
	{
		signo = 1;
		num *= -1;
		num_length = numberLength(num) + 1;
	}
	else
		num_length = numberLength(num);
	num_string = malloc(sizeof(*num_string) * num_length + 1);
	if (num_string == NULL)
		exit(1);
	num_string = numberToString(num_string, num, num_length);
	if (signo)
		num_string[0] = '-';
	return (num_string);
}
char *printPercentage(va_list __attribute__((unused)) pa)
{
	return ("%");
}

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

/*----TAKE TO PRINTER.c*/
unsigned int print(char *str)
{
	unsigned int string_length = 0;
	/*get final lenght + null char*/
	string_length = get_string_length(str);
	write(1, str, string_length);
	return (string_length);
}

int _printf(const char *format, ...)
{
	va_list pa;                     /*list of arguments*/
	char *string = "";              /*string for final result*/
	unsigned int i = 0;             /*loops iterators*/
	int j;                          /*loops iterators*/
	unsigned int string_length = 0; /*final lenght of string*/
	int flag_number = 5;            /*number of possible flags in format %*/
	formats formatos[6] = {{"c", printChar},
			       {"s", printString},
			       {"d", printIntenger},
			       {"i", printIntenger},
			       {"%", printPercentage},
			       {NULL, NULL}}; /*formats*/
	char directive_string[6];             /*extract of the directive string + null*/
	int directive_length = 0;             /*length of directive*/
	char *sub_string = NULL;              /*result after analysis of directive*/
	va_start(pa, format);                 /*fill list of parameters*/
	/*go through string*/
	while (*(format + i))
	{
		if (format[i] == '%')
		{
			/*get code directive chars from format after % encountered*/
			for (j = 0; j < flag_number; j++)
			{
				if (format[(i + 1) + j] != '\0')
					directive_string[j] = format[(i + 1) + j];
			}
			if (directive_string[j] != '\0')
				directive_string[j] = '\0';
			/*get lenght of directive and look if it's valid*/
			directive_length = validate_directive(formatos, directive_string, &flag_number);
			/*send directive to analyze and return string result*/
			sub_string = analyse_code(directive_string, formatos, pa, &directive_length);
			/*sub_string to buffer*/
			string = sub_string_buffer(sub_string, string);
			/*skip directive length and keep buffering*/
			i += 2 + directive_length; /*2 represents acutal % position*/
			continue;
		}
		else
			string = buffer(format[i], string); /*send char to buffer*/
		i++;
	}
	/*print string*/
	string_length = print(string);
	/*kill them all*/
	va_end(pa);            /*kill list*/
	if (string[0] != '\0') /*kill string*/
		free(string);
	return (string_length);
}

/*----TAKE TO MAIN.c*/
int main()
{
	int len;
	int len2;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len2);
	printf("Length:[%d, %i]\n", len, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);

	_printf("\n\nPRUEBAS PROPIAS\n\n");
	_printf("Ho%%la %c %s %i %d\n", 'A', "bebé", 234, 567);
	printf("Ho%%la %c %s %i %d\n", 'A', "bebé", 234, 567);
	return (0);
}
