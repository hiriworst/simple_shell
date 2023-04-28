#include "main.h"
/**
 * _getline - line
 * Return: 0
 */
int _getline(void)
{
	char *string;
	size_t size;
	ssize_t bytes_read = 0;
	int i;

	string = (char *)malloc(size);
	if (bytes_read == -1)
	{
		puts("hsh");
	}
	else
		for (i = 0; i < 1; i++)
		{
			printf("$ ");
			bytes_read = getline(&string, &size, stdin);
		}
	return (0);
}
/**
 * _strtok - string or a line
 * Return: 0
 */
int _strtok(void)
{
	char *str = " ";
	char *token = strtok(str, " ");

	while (token != NULL)
	{
		printf("%s", token);
		token = strtok(NULL, " ");
	}
	return (0);
}
/**
* _fork - cew process
*Return: 0
*/
void _fork(void)
{
	char *argv[] = {"/bin/ls", "-l", ".", NULL};

	pid_t pid = fork();

	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
	}
	else
	{
		wait(NULL);
	}
}
/**
* sig_handler - cfd input
* @signum: int
*Return: void
*/
void sig_handler(int signum)
{

	if (signum == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}
/**
 *main - func
 *Return: Always(0)
 */
int main(void)
{
	int st = 1;

	signal(SIGINT, sig_handler);
	while (st)
		{
		_getline();
		_strtok();
		_fork();
		}
	return (0);
}
