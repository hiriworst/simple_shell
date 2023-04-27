#include "main.h"


/**
 * analyze_patterns - Entry Point
 * @data: input
 * @arguments: input
**/

void analyze_patterns(functi_comm_global *data, char **arguments)
{
	int i;

	for (i = 0; arguments[i] != NULL; i++)
		arguments[i] = pattern_handler(data, arguments[i]);
}

/**
 * pattern_handler - Entry Point
 * @data: input
 * @string: input
 * Return: string
**/

char *pattern_handler(functi_comm_global *data, char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '$' && string[i + 1] != '\0')
			string = replace_value(data, &i, string);
	}

	return (string);
}

/**
 * replace_value - Entry Point
 * @data: input
 * @index: input
 * @string: input
 * Return: string
**/

char *replace_value(functi_comm_global *data, int *index, char *string)
{
	int i, str_len_new, anc_len;
	char *value;

	i = *index;
	i++;

	value = replacement(data, index, string + i);
	if (value == NULL)
	{
		string = _strcpy(string, "");

		return (string);
		;
	}

	anc_len = _strlen(string);
	str_len_new = _strlen(value) + 1;

	string = _realloc(string, anc_len, str_len_new);
	string = _strcpy(string, value);

	free_memory_p(value);
	*index = i;
	return (string);
}
