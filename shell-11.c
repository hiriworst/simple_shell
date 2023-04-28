#include "main.h"

/**
 * _stat - function that shows sistem files
 * @bftoken: buffer pointer with commands
 * @pat: pointer with the location of each directory
 * Return: 1 on success
 **/
int _stat(char **bftoken, char **pat)
{
	char *newval = NULL, *newval2 = NULL;
	int x;

	struct stat sb;

	for (x = 1 ; pat[x] != NULL ; x++)
	{
		newval = str_concat(pat[x], "/");
		newval2 = str_concat(newval, bftoken[0]);

		if (stat(newval2, &sb) == 0)
		{
			bftoken[0] = newval2;
			free(newval);
			free(pat[0]);
			free(pat);
			return (1);
		}
		free(newval);
		free(newval2);
	}
	free(pat[0]);
	free(pat);
	return (0);
}
