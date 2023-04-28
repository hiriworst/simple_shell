#include "main.h"

/**
 * _strdup - returns a pointer to a new space in memery
 * @str: character in string
 *
 * Return: NULL if str is NULL, otherwise returns x
 **/
char *_strdup(char *str)
{
	char *x;
	int y;
	int z;

	if (str == NULL)
		return (NULL);
	for (y = 0 ; str[y] != '\0' ; y++)
		;
	y++;
	x = malloc(y * sizeof(char));

	if (x == NULL)
	{
		return (NULL);
	}
	for (z = 0 ; z < y ; z++)
	{
		x[z] = str[z];
	}
	return (x);
}
