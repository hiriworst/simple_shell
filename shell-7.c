#include "main.h"

/**
 * exefork - execute another function after child system process
 * @token_mdf: Process to execute via pointers
 * @input_num: If process does happen then execute
 * @environ: Environment variables
 *
 * Return: 1
 **/
int exefork(char **token_mdf, int input_num, char **environ)
{
	pid_t child_pid;
	int result;

	if (token_mdf == NULL)
	{
	return (-1);
	}
	child_pid = fork();

	if (child_pid < 0)
	{
		perror("./hsh: ");
		exit(1);
	}
	else if (child_pid == 0)
	{
		if (execve(token_mdf[0], token_mdf, environ) == -1)
		{
			perror("./hsh: ");
			free(token_mdf);
			exit(1);
		}
		exit(0);
	}
	else
	{
		if (input_num == 1)
			free(token_mdf[0]);

		free(token_mdf);
		wait(&result);
	}
	return (1);
}
