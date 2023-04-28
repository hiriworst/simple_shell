#include "main.h"

/**
 * linetoken - Breaks the line from prompt into tokens
 * @linea: line from getline
 * @env: env variable
 *
 * Return: buffer which is an array of pointers
 **/
char **linetoken(char *linea, char **env)
{
	int count = 0;
	char *line;
	char **buffer = _calloc(sizeof(char *), 64);

	line =	strtok(linea, " \n\t\r\a");

	while (line != NULL)
	{
		buffer[count] = line;
		count++;
		line = strtok(NULL, " \n\t\r\a");
	}
	if (buffer[0] == NULL)
		buffer[count] = "\n";

	if ((_strcmp(buffer[0], "exit") == 0) && buffer[1] == NULL)
	{
		free(linea);
		free(buffer);
		exit(0);
	}
	if ((_strcmp(buffer[0], "env") == 0) && buffer[1] == NULL)
		find_env(env);

	return (buffer);
}
