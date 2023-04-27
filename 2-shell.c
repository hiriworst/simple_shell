#include "main.h"

/**
 * check_dif - check_dif of the arg
 *
 * @arguments: Commands and arguments to execute
 * @data: General information about the shell
 * @buff: ptr char
 * Return: succes or fail
 **/
void check_dif(char **arguments, functi_comm_global *data, char *buff)
{
	char *cmd;
	int status;

	if (*arguments == NULL || arguments == NULL)
		return;

	cmd = arguments[0];
	data->command = cmd;
	if (func_read_d(data, arguments) == _TRUE)
		return;

	status = is_file(cmd);
	if (status == NON_PERMISSIONS)
	{
		data->status_code = 126;
		data->error_code = _CODE_EACCES;
		error(data);
		return;
	}

	if (status == 1)
	{
		fun(cmd, arguments, data, buff);
		return;
	}

	if (folder_current(cmd, arguments, buff, data) == _TRUE)
		return;

	data->value_path = which(cmd, data);
	if (data->value_path != NULL)
	{
		fun(data->value_path, arguments, data, buff);
		free_memory_p((void *) data->value_path);
		return;
	}

	data->status_code = 127;
	data->error_code = _CODE_CMD_NOT_EXISTS;
	error(data);
}
