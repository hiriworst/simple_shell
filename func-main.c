#include "main.h"

/**
 * main - shell main function
 * Return: digit
 */

int main(void)
{
	char *buff = NULL, **args;
	size_t con_length = 0;
	ssize_t size_len = 0;
	int quit = 0;

	while (1)
	{
		if (isatty(0))
		{
			printf("hsh$ ");
		}

		size_len = getline(&buff, &con_length, stdin);
		if (size_len == -1 || _strcmp("exit\n", buff) == 0)
		{
			free(buff);
			break;
		}
		buff[size_len - 1] = '\0';

		if (_strcmp("env", buff) == 0)
		{
			_var_location();
			continue;
		}

		if (line_free(buff) == 1)
		{
			quit = 0;
			continue;
		}

		args = _split(buff, " ");
		args[0] = search_path(args[0]);

		if (args[0] != NULL)
			quit = run_func(args);
		else
			perror("Error");
		free(args);
	}
	return (quit);
}


