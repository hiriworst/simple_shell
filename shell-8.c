#include "main.h"

/**
 * findpath - executable input command line
 * @environ: Env variables as a pointer
 *
 * Return: pointer_to_string_char
 **/
char **findpath(char **environ)
{
	int x;
	char **pointer_to_string_char;

	for (x = 0 ; environ[x] != NULL ; x++)
	{
		if (environ[x][0] == 'P' && environ[x][2] == 'T')
		{
			pointer_to_string_char = usepath(environ[x]);
		}
	}
	return (pointer_to_string_char);
}

/**
 * usepath - Creates tokens form the directory PATH
 * @var_path_find_str: variable of var_strings
 *
 * Return: output(str_ptr)
 **/
char **usepath(char *var_path_find_str)
{
	int count = 0;
	char *str_ptr = NULL;
	char **fun_string_line = _calloc(sizeof(char *), 64);
	char *var_path_find_str_copy = NULL;

	if (fun_string_line == NULL)
	{
		return (NULL);
	}

	var_path_find_str_copy = _strdup(var_path_find_str);
	str_ptr = strtok(var_path_find_str_copy, "=:");

	while (str_ptr != NULL)
	{
		fun_string_line[count] = str_ptr;
		count++;
		str_ptr = strtok(NULL, "=:");
	}
	return (fun_string_line);
}
