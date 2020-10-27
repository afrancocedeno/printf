#include "holberton.h"

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
 * @signo: sign of the number
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
