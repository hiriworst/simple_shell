#include "main.h"

/**
 * quit - exit functionality
 * @data: info of the shell
 * @arguments: Arguments
 * Return: success
 **/
void quit(functi_comm_global *data, char **arguments)
{
	int status_code, status;

	status = _TRUE;
	if (arguments[1] != NULL)
		status = num_elem_data(data, arguments[1]);

	if (status == _FALSE)
		return;

	status_code = data->status_code;

	free_memory_pp((void **) arguments);
	free_memory_p((void *) data->buffer);
	free_memory_p((void *) data->environment);
	free_memory_p((void *) data);

	exit(status_code);
}

/**
 * num_elem_data - Control the argument of exit
 *
 * @data: General information about the shell
 * @number: Argument of the builtin
 *
 * Return: succes value or false
 **/
int num_elem_data(functi_comm_global *data, char *number)
{
	int _number;

	_number = _atoi(number);

	if (_number < 0 || contains_letter(number))
	{
		data->status_code = 2;
		data->error_code = _CODE_ILLEGAL_NUMBER;
		any_faulty_found_outside(data, number);
		return (_FALSE);
	}

	if (_number > 255)
		data->status_code = _number % 256;
	else
		data->status_code = _number;

	return (_TRUE);
}
