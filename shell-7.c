#include "main.h"

/**
 * exefork - execute another function after child system process
 * @function_modified_token: Process to execute via pointers
 * @inputed_digit_or_string: If process does happen then execute
 * @environ: Environment variables
 *
 * Return: 1
 **/
int exefork(char **function_modified_token, int inputed_digit_or_string, char **environ)
{
	pid_t child_pid;
	int result;

	if (function_modified_token == NULL)
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
		if (execve(function_modified_token[0], function_modified_token, environ) == -1)
		{
			perror("./hsh: ");
			free(function_modified_token);
			exit(1);
		}
		exit(0);
	}
	else
	{
		if (inputed_digit_or_string == 1)
			free(function_modified_token[0]);

		free(function_modified_token);
		wait(&result);
	}
	return (1);
}
