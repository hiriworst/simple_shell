#include "main.h"

/**
 * local_func_command - function to check and execute
 *
 * @data: data for the project description
 * @arguments: parametre arg
 *
 * Return: succes or fail
 **/

int local_func_command(functi_comm_global *data, char **arguments)
{
	int result;

	result = func_read_d(data, arguments);
	if (result == _FALSE)
		return (_FALSE);

	return (_TRUE);
}

/**
 * func_read_d - check if or not
 * @data: shell descriptions
 * @arguments: com arg
 * Return: succes or fail
 **/
int func_read_d(functi_comm_global *data, char **arguments)
{
	int i, size;

	func_gen_struct_fil_name local_func_command[] = {
		{"exit", bin_exit},
		{"env", bin_env}
	};
	size = sizeof(local_func_command) / sizeof(local_func_command[0]);
	for (i = 0; i < size; i++)
	{
		if (_strcmp(data->command, local_func_command[i].command) == 0)
		{
			local_func_command[i].func(data, arguments);
			return (_TRUE);
		}
	}
	return (_FALSE);
}
