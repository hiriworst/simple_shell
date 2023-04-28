#include "main.h"

/**
 * _stat - function for files and sys cnge
 * @data_tkn: argments
 * @pat: locate_point
 * Return: zero or one
 **/
int _stat(char **data_tkn, char **pat)
{
	char *var_digit = NULL, *more_var_numb = NULL;
	int x;

	struct stat sb;

	for (x = 1 ; pat[x] != NULL ; x++)
	{
		var_digit = str_concat(pat[x], "/");
		more_var_numb = str_concat(var_digit, data_tkn[0]);

		if (stat(more_var_numb, &sb) == 0)
		{
			data_tkn[0] = more_var_numb;
			free(var_digit);
			free(pat[0]);
			free(pat);
			return (1);
		}
		free(var_digit);
		free(more_var_numb);
	}
	free(pat[0]);
	free(pat);
	return (0);
}
