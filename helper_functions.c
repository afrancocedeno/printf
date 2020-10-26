#include "holberton.h"
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
