#include "main.h"


/**
 * command_env - variable_env get
 *
 * @name: Environment variable to get
 *
 * Return: On success value of @name
 * On error, NULL
 **/
char *command_env(const char *name)
{
	char **env;
	char *aux, *get_tkn, *value;
	int size;

	size = _strlen((char *) name);

	for (env = environ; *env; ++env)
	{
		aux = _strdup(*env);

		get_tkn = strtok(aux, "=");
		if (get_tkn == NULL)
		{
			free(aux);
			return (NULL);
		}

		if (_strlen(get_tkn) != size)
		{
			free(aux);
			continue;
		}

		if (_strcmp((char *) name, aux) == 0)
		{
			get_tkn = strtok(NULL, "=");
			value = _strdup(get_tkn);

			free(aux);
			return (value);
		}

		free(aux);
	}

	return (NULL);
}

/**
 * specific_elem - current directory wanted
 *
 * @filename: input accepted from
 * @data: General data about the shell
 *
 * Return: pointer
 */
char *specific_elem(char *filename, functi_comm_global *data)
{
	char *path, *tmp_path, *get_tkn;
	char *cut;
	int size;

	(void) data;

	path = command_env("PATH");
	if (path == NULL)
		return (NULL);

	get_tkn = strtok(path, ":");

	size = _strlen(filename) + 2;
	cut = malloc(size * sizeof(char));
	cut = _strcpy(cut, "/");
	cut = _strcat(cut, filename);

	while (get_tkn != NULL)
	{
		tmp_path = malloc(_strlen(get_tkn) + size);
		tmp_path = _strcpy(tmp_path, get_tkn);
		tmp_path = _strcat(tmp_path, cut);

		if (is_executable(tmp_path) == PERMISSIONS)
		{
			free(cut);
			free(path);
			return (tmp_path);
		}
		get_tkn = strtok(NULL, ":");

		free(tmp_path);
	}

	free(path);
	free(cut);

	return (NULL);
}

/**
 * now_working - working path checking
 *
 * @path: argument path
 * @data: info of da
 **/
void now_working(char *path, functi_comm_global *data)
{
	data->now_working = _FALSE;

	if (path == NULL)
		return;

	if (path[0] == ':')
		data->now_working = _TRUE;
}

/**
 * whole_env - Get all the environment
 **/
void whole_env(void)
{
	char **tmp;
	int i;

	for (i = 0, tmp = environ; tmp[i] != NULL; i++)
	{
		print(tmp[i]);
		_putchar('\n');
	}
}

