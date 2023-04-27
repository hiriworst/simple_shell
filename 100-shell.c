#include "main.h"


/**
 * replacement - function
 * @data: input
 * @index: input
 * @string: input
 * Return: string
**/

char *replacement(functi_comm_global *data, int *index, char *string)
{
	char *tmp;
	char symbol;

	(void) index;

	symbol = *string;
	if (symbol != '?' && symbol != '$')
	{
		tmp = envrionment_replace(data, string);
		return (tmp);
	}

	tmp = (symbol == '$') ? to_string(data->pid) :
		to_string(data->status_code);

	return (tmp);
}

/**
 * envrionment_replace - Entry Point
 * @data: input
 * @environment: input
 * Return: succes
**/

char *envrionment_replace(functi_comm_global *data, char *environment)
{
	char *env;

	(void) data;

	env = _getenv(environment);
	if (env != NULL)
		return (env);

	return (NULL);
}
