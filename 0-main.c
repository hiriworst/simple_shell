#include "main.h"
#include <stdlib.h>


/**
 * main - main function to run
 * @argc: args count
 * @argv: vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	    char *command = NULL;
	    char **command_now = NULL;
	    
	    config data;
	(void)argc;
	signal(SIGINT, init_manage);
	initialize(&data);
	data.shell_name = argv[0];
	main_unix(&data);
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

