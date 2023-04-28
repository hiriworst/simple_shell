#include "main.h"

/**
 * _capture - get env variables
 * @ptr_var: ptr variable
 * Return: success
 */

char *_capture(char *ptr_var)
{
	int i = 0, j;
	int result;

	while (environ[i])
	{
		result = 1;

		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != ptr_var[j])
				result = 0;
		}
		if (result == 1)
		{
			break;
		}
		i++;
	}
	return (&environ[i][j + 1]);
}

/**
 * _var_location - env echos
*/
void _var_location(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
