#include "main.h"

/**
 * get_path_location - search file between the path
 * @command: command path
 * Return: path
 */

char *get_path_location(char *command)
{
	char *path = _capture("PATH"), *path_cpy;
	char **separate_path;
	char *add_to_other = NULL;
	int i = 0, where_to_lenth = 0;
	struct stat info;

	if (stat(command, &info) == 0)
		return (command);

	path_cpy = malloc(_strlen(path) + 1);

	path_cpy = _strcpy(path_cpy, path);
	separate_path = _split(path_cpy, ":");

	while (separate_path[i])
	{
		where_to_lenth = _strlen(separate_path[i]);

		if (separate_path[i][where_to_lenth - 1] != '/')
			add_to_other = _strcat(separate_path[i], "/");

		add_to_other = _strcat(separate_path[i], command);

		if (stat(add_to_other, &info) == 0)
			break;

		i++;
	}

	free(path_cpy);

	if (!separate_path[i])
	{
		free(separate_path);
		return (NULL);
	}

	free(separate_path);
	return (add_to_other);
}

