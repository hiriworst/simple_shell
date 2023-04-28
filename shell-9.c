#include "main.h"

/**
 * linetoken - separates every lines to different tkkns
 * @ptr_path_location: first_argument
 * @place_var: second_argument
 *
 * Return: arr of ptrs
 **/
char **linetoken(char *ptr_path_location, char **place_var)
{
	int result = 0;
	char *path_dir;
	char **var_tkn = _calloc(sizeof(char *), 64);

	path_dir =	strtok(ptr_path_location, " \n\t\r\a");

	while (path_dir != NULL)
	{
		var_tkn[result] = path_dir;
		result++;
		path_dir = strtok(NULL, " \n\t\r\a");
	}
	if (var_tkn[0] == NULL)
	{
		var_tkn[result] = "\n";
	}

	if ((_strcmp(var_tkn[0], "exit") == 0) && var_tkn[1] == NULL)
	{
		free(ptr_path_location);
		free(var_tkn);
		exit(0);
	}
	if ((_strcmp(var_tkn[0], "place_var") == 0) && var_tkn[1] == NULL)
		find_env(place_var);

	return (var_tkn);
}
