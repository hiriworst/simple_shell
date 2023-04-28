#include "main.h"

/**
 * main_unix - functionality of unix
 * @data: input data params
 * Return: Nothing
 */
void main_unix(config *data)
{
	while (1)
	{
		line_value(data);
		if (split_string(data) == 0)
		{
			continue;
		}
		if (builts_commands(data) == 1)
		{
			continue;
		}
		check_path(data);
		find_child_exec(data);
	}
}

/**
 * line_value - inputs function
 * @data: input data params
 * Return: Nothing
 */
void line_value(config *data)
{
	register int len;
	size_t buffer_size = 0;
	char *ptr, *ptr2;

	data->args = NULL;
	data->env_list = NULL;
	data->count_line++;
	if (isatty(STDIN_FILENO))
	{
		get_prompt();
	}
	len = getline(&data->buffer, &buffer_size, stdin);
	if (len == EOF)
	{
		if (isatty(STDIN_FILENO))
		{
			put_new_line();
		}
		if (data->error_status)
		{
			exit(data->error_status);
		}
		exit(EXIT_SUCCESS);
	}
	ptr = _strchr(data->buffer, '\n');
	ptr2 = _strchr(data->buffer, '\t');
	if (ptr || ptr2 != NULL)
	{
		null_bytes(data->buffer, len - 1);
	}
	_commments(data->buffer);
}

/**
 * _commments - remove comments from input string
 * @str: input string
 * Return: length of remaining string
 */
void _commments(char *str)
{
	register int i = 0;
	_Bool is_not_first = false;

	while (str[i])
	{
		if (i == 0 && str[i] == '#')
		{
			null_bytes(str, i);
			return;
		}
		if (is_not_first)
		{
			if (str[i] == '#' && str[i - 1] == ' ')
			{
				null_bytes(str, i);
				return;
			}
		}
		i++;
		is_not_first = true;
	}
}

/**
 * find_child_exec - handle and exec
 * @data: data inputs
 * Return: Nothing
 */
void find_child_exec(config *data)
{
	int status;
	pid_t f1 = fork();

	list_ptr_ar(data);
	if (f1 == -1)
	{
		perror("error\n");
		free_member(data);
		free_args(data->env_list);
		exit(1);
	}
	if (f1 == 0)
	{
		if (execve(data->full_path, data->args, data->env_list) == -1)
		{
			handle_errors(data);
			free_member(data);
			free_args(data->env_list);
			if (errno == ENOENT)
				exit(127);
			if (errno == EACCES)
				exit(126);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			data->error_status = WEXITSTATUS(status);
		}
		free_args_and_buffer(data);
		free_args(data->env_list);
	}
}

/**
 * list_ptr_ar - list to arrays
 * @data: input data params
 */
void list_ptr_ar(config *data)
{
	register int i = 0;
	size_t count = 0;
	char **env_list = NULL;
	linked_l *tmp = data->env;

	count = list_len(data->env);
	env_list = malloc(sizeof(char *) * (count + 1));

	if (!env_list)
	{
		perror("Malloc failed\n");
		exit(1);
	}
	while (tmp)
	{
		env_list[i] = _strdup(tmp->string);
		tmp = tmp->next;
		i++;
	}
	env_list[i] = NULL;
	data->env_list = env_list;
	free(env_list);
}
