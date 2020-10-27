#include "holberton.h"
#include <stdio.h> /*THIS GOES IN MAIN*/
#include <limits.h>

/*----TAKE TO MAIN.c*/
int main()
{
	int l = ((INT_MAX));
	int w = ((INT_MIN));
	_printf("%d\n", 1024);
	printf("%d\n", 1024);
	_printf("%d\n", -1024);
	printf("%d\n", -1024);
	_printf("%d\n", 0);
	printf("%d\n", 0);
	_printf("%d\n", INT_MAX);
	printf("%d\n", INT_MAX);
	_printf("%d\n", INT_MIN);
	printf("%d\n", INT_MIN);
	_printf("%d\n", l);
	printf("%d\n", l);
	_printf("%d\n", w);
	printf("%d\n", w);
	_printf("There is %d bytes in %dKB\n", 1024, 1);
	printf("There is %d bytes in %dKB\n", 1024, 1);
	_printf("%d - %d = %d\n", 1024, 2048, -1024);
	printf("%d - %d = %d\n", 1024, 2048, -1024);
	_printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	_printf("%i\n", 1024);
	printf("%i\n", 1024);
	_printf("%i\n", -1024);
	printf("%i\n", -1024);
	_printf("%i\n", 0);
	printf("%i\n", 0);
	_printf("%i\n", INT_MAX);
	printf("%i\n", INT_MAX);
	_printf("%i\n", INT_MIN);
	printf("%i\n", INT_MIN);
	_printf("%i\n", l);
	printf("%i\n", l);
	_printf("%i\n", w);
	printf("%i\n", w);
	_printf("There is %i bytes in %iKB\n", 1024, 1);
	printf("There is %i bytes in %iKB\n", 1024, 1);
	_printf("%i - %i = %i\n", 1024, 2048, -1024);
	printf("%i - %i = %i\n", 1024, 2048, -1024);
	_printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	_printf("%d == %i\n", 1024, 1024);
	printf("%d == %i\n", 1024, 1024);
	_printf("iddi%diddiiddi\n", 1024);
	printf("iddi%diddiiddi\n", 1024);
	_printf("%d\n", 10000);
	printf("%d\n", 10000);
	_printf("%i\n", 10000);
	printf("%i\n", 10000);
	return (0);
}
