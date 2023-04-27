#include "main.h"


/**
 * information_user_send - message to send
 *
 * @data: info about shell
 *
 * Return: message
 **/
char *information_user_send(functi_comm_global data)
{
	int i, n_options;
	error_t messages[] = {
		{_ENOENT, _CODE_ENOENT},
		{_EACCES, _CODE_EACCES},
		{_CMD_NOT_EXISTS, _CODE_CMD_NOT_EXISTS},
		{_ILLEGAL_NUMBER, _CODE_ILLEGAL_NUMBER}
	};

	n_options = sizeof(messages) / sizeof(messages[0]);
	for (i = 0; i < n_options; i++)
		if (data.error_code == messages[i].code)
			return (messages[i].message);

	return ("");
}

/**
 * faulty - error message print
 *
 * @data: about shell
 **/
void faulty(functi_comm_global *data)
{
	char *message;
	char *number;
	char *aux;
	int size_number, size_message;

	number = NULL;
	message = information_user_send(*data);
	number = to_string(data->n_commands);

	size_number = _strlen(number);
	size_message = _strlen(data->argv[0]);

	aux = malloc(size_message + size_number + 3);

	aux = _strcpy(aux, data->argv[0]);
	aux = _strcat(aux, ": ");
	aux = _strcat(aux, number);

	message = join_words(aux, data->command, message, ": ");
	print_err(message);

	free(message);
	free(number);
	free(aux);
}

/**
 * any_faulty_found_outside - Print the error with extra rmation
 *
 * @data: General information about the shell
 * @exceed:  information
 **/
void any_faulty_found_outside(functi_comm_global *data, char *exceed)
{
	char *message, *number, *aux, *aux2;
	int size_number, size_message, size_extra;

	number = NULL;
	message = information_user_send(*data);
	number = to_string(data->n_commands);

	size_number = _strlen(number);
	size_message = _strlen(data->argv[0]);
	size_extra = _strlen(exceed);

	aux = malloc(size_message + size_number + 3);
	aux = _strcpy(aux, data->argv[0]);
	aux = _strcat(aux, ": ");
	aux = _strcat(aux, number);

	aux2 = malloc(_strlen(message) + size_extra + 3);
	aux2 = _strcpy(aux2, message);
	aux2 = _strcat(aux2, ": ");
	aux2 = _strcat(aux2, exceed);

	message = join_words(aux, data->command, aux2, ": ");
	print_err(message);

	free(message);
	free(number);
	free(aux);
	free(aux2);
}
