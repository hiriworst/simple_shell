#include "main.h"
/**
 * program_run - similar to puts in C
 * @first_str: pointer
 *
 * Return: int
 */
void program_run(char **first_str)
{

	char *argumment = (*(first_str + 1));
	char *s, *slash = "/";
	char *o;

	char *var_to_echo = *first_str;
	char *argv[4];

	if ((access(first_str[0], F_OK) == 0))
	{
		argv[0] = first_str[0];
		argv[1] = argumment;
		argv[2] = ".";
		argv[3] = NULL;

		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
		}
	}
	else
	{
		o = find_command(var_to_echo);

		slash = str_concat(o, slash);

		s = str_concat(slash, *first_str);

		argv[0] = s;
		argv[1] = argumment;
		argv[2] = ".";
		argv[3] = NULL;

		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
		}
	}
}
