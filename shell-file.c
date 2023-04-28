#include "main.h"

/**
 * _strdup -   space_duplicate or nw to a ptr
 * @cha_string_func_sh: character in string
 *
 * Return: nothing or looper
 **/
char *_strdup(char *cha_string_func_sh)
{
	char *looper;
	int dltn;
	int where_to_func;

	if (cha_string_func_sh == NULL)
		return (NULL);
	for (dltn = 0 ; cha_string_func_sh[dltn] != '\0' ; dltn++)
		;
	dltn++;
	looper = malloc(dltn * sizeof(char));

	if (looper == NULL)
	return (NULL);
	for (where_to_func = 0 ; where_to_func < dltn ; where_to_func++)
	{
		looper[where_to_func] = cha_string_func_sh[where_to_func];
	}
	return (looper);
}

