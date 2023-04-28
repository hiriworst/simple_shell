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
	char **val_buf_variable = _calloc(sizeof(char *), 64);

	path_dir =	strtok(ptr_path_location, " \n\t\r\a");

	while (path_dir != NULL)
	{
		val_buf_variable[result] = path_dir;
		result++;
		path_dir = strtok(NULL, " \n\t\r\a");
	}
	if (val_buf_variable[0] == NULL)
	{
		val_buf_variable[result] = "\n";
	}

	if ((_strcmp(val_buf_variable[0], "exit") == 0) && val_buf_variable[1] == NULL)
	{
		free(ptr_path_location);
		free(val_buf_variable);
		exit(0);
	}
	if ((_strcmp(val_buf_variable[0], "place_var") == 0) && val_buf_variable[1] == NULL)
		find_env(place_var);

	return (val_buf_variable);
}
