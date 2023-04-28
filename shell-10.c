#include "main.h"

/**
 * main - Executes commands
 * @ac: Argument counts
 * @av: Arguments in an array
 * @environ: Array of pointers of the variable environment
 *
 * Return: Always 0
 **/
int main(int ac, char *av[], char **environ)
{

	char *bf = NULL;
	char **bftoken, **pat;
	ssize_t characters;
	size_t bfsize = 0;
	int goesin = 0;
	(void)ac;
	(void)av;

	while (1)
	{

		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "$ ", 2);
		characters = getline(&bf, &bfsize, stdin);
		if (characters == EOF)
		{
			free(bf);
			exit(0); }

		if (*bf != '\n')
		{
			bftoken = linetoken(bf, environ);
			if ((_strcmp(bftoken[0], "\n") != 0) && (_strcmp(bftoken[0], "env") != 0))
			{
				pat = findpath(environ);
				goesin = _stat(bftoken, pat);
				exefork(bftoken, goesin, environ); }
			else
			{
				free(bftoken);
			}
		}
	}
	return (0);
}
