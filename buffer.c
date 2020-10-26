#include "holberton.h"
/**
 *
 */
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
