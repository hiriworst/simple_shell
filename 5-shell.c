#include "main.h"

/**
 * fun - fun a command in other process
 *
 * @command: Command to fun
 * @arguments: Arguments line
 * @data: info about shell
 * @buff: Line readed
 * Return : no rtn
 **/
void fun(char *command, char **arguments, functi_comm_global *data, char *buff)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(command, arguments, environ);
		perror("./sh");

		free_memory_pp((void *) arguments);

		if (data->value_path != NULL)
		{
			free(data->value_path);
			data->value_path = NULL;
		}

		free(data);
		free(buff);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			data->status_code = WEXITSTATUS(status);
	}
}


/**
 * fol_cur - execution function
 *
 * @cmd: input_comm
 * @arguments: args of comm
 * @buff: Line readed
 * @data: arg inf
 *
 * Return: state
 **/
int fol_cur(char *cmd, char **arguments, char *buff, functi_comm_global *data)
{

	if (data->now_working == _FALSE)
		return (_FALSE);

	if (is_executable(cmd) == PERMISSIONS)
	{
		fun(cmd, arguments, data, buff);
		return (_TRUE);
	}

	return (_FALSE);
}
