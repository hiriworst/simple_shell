#include "main.h"

/**
 * code_identifiar - if fist code is/
 * @first_str: first arg
 * Return: zero or nothing
 */
int code_identifiar(char *first_str)
{
	int result = 0;

	while (first_str[result])
	{
		if (first_str[0] == '/')
		{
			printf("%c\n", first_str[0]);
			return (1);
		}

		result++;
	}
	return (0);
}

/**
 * differentiate_func - compare func
 * @fast_string:       arg first
 * @second_string: arg second
 * Return: suc or fail
 */
int differentiate_func(char *fast_string, char *second_string)
{
	int i = 0;

	for (; (*second_string != '\0' && *fast_string != '\0') &&
			*fast_string == *second_string; fast_string++)
	{
		if (i == 3)
			break;
		i++;
		second_string++;
	}

	return (*fast_string - *second_string);
}

/**
 * compareEnv - identifies if first char is a slash.
 * @fast_string: first string
 * @second_string: exit string
 * Return:false or true
 */
int compareEnv(char *fast_string, char *second_string)
{
	int i = 0;

	for (; (*second_string != '\0' && *fast_string != '\0') &&
			*fast_string == *second_string; fast_string++)
	{
		if (i == 2)
			break;
		i++;
		second_string++;
	}

	return (*fast_string - *second_string);
}
/**
 * search_str - inpts search function.
 * @argumnt: first arg
 * Return: buf
 **/
char **search_str(char *argumnt)
{
	char **buf = malloc(1024 * sizeof(char *));
	char *separate;
	int i = 0;
	char *delim = " \t\n";


	separate = strtok(argumnt, delim);

	while (separate != NULL)
	{
		buf[i] = separate;
		i++;
		separate = strtok(NULL, delim);
	}
	program_run(buf);
	return (buf);

}
/**
 * fun_cont - no close the shell
 * @no_stop: load
 **/
void  fun_cont(int no_stop)
{
	(void) no_stop;
	write(1, "\n$ ", 3);
}
