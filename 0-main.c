#include "main.h"

/**
 * main - main function to run
 * @ac: args count
 * @av: vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	config data;
	(void)ac;
	signal(SIGINT, init_manage);
	initialize(&data);
	data.shell_name = av[0];
	shell(&data);
	return (0);
}

/**
 * initialize - initialize member values
 * @data: input data
 * Return: on success
 */
config *initialize(config *data)
{
	data->env = generateLinkedList(environ);
	data->env_list = NULL;
	data->args = NULL;
	data->buffer = NULL;
	data->path = _getenv("PATH", environ);
	data->full_path = NULL;
	data->count_line = 0;
	data->shell_name = NULL;
	data->error_status = 0;
	return (data);
}

