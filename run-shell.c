#include "main.h"

/**
 * run_func - run path of the child process
 * @args: parameter arg counts
 * Return: result
 */

int run_func(char **args)
{
	int id = fork(), result;

	if (id == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror("Error");
	}
	else
	{
		wait(&result);
		if (WIFEXITED(result))
		{
			result = WEXITSTATUS(result);
		}
	}

	return (result);
}

