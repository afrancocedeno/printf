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
 * @signo: 1 if its negative, 0 if its not
 *
 * Return: number as a string
 */
char *numberToString(char *s, int n, int length, int signo)
{

	while (length > 0)
	{
		s[length - 1] = (n % 10) + '0';
		n /= 10;
		length--;
	}
	if (signo && length == 0)
		s[0] = '-';
	else
		s[0] = (n % 10) + '0';
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
