#include "holberton.h"
#include <stdio.h> /*THIS GOES IN MAIN*/

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
