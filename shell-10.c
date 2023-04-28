#include "main.h"

/**
 * main - main fuction give output
 * @argc: first argument
 * @argv: second argument
 * @environ: arrs
 *
 * Return: 0
 **/
int main(int argc, char *argv[], char **environ)
{

	char *data_fork = NULL;
	char **elem_data, **pat;
	ssize_t characters;
	size_t bfsize = 0;
	int input_func = 0;
	(void)argc;
	(void)argv;

	while (1)
	{

		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "$ ", 2);
		characters = getline(&data_fork, &bfsize, stdin);
		if (characters == EOF)
		{
			free(data_fork);
			exit(0); }

		if (*data_fork != '\n')
		{
			elem_data = linetoken(data_fork, environ);
			if ((_strcmp(elem_data[0], "\n") != 0) && (_strcmp(elem_data[0], "env") != 0))
			{
				pat = findpath(environ);
				input_func = _stat(elem_data, pat);
				exefork(elem_data, input_func, environ); }
			else
			{
				free(elem_data);
			}
		}
	}
	return (0);
}
