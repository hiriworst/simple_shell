#include "main.h"

/**
 * findpath - Gets the path to execute commands
 * @environ: Env variables as a pointer
 *
 * Return: tokpa
 **/
char **findpath(char **environ)
{
	int x;
	char **tokpa;

	for (x = 0 ; environ[x] != NULL ; x++)
	{
		if (environ[x][0] == 'P' && environ[x][2] == 'T')
		{
			tokpa = usepath(environ[x]);
		}
	}
	return (tokpa);
}

/**
 * usepath - Creates tokens form the directory PATH
 * @fpat: Path variables in form of pointers
 *
 * Return: tokpa
 **/
char **usepath(char *fpat)
{
	int count = 0;
	char *usep = NULL;
	char **tokpat = _calloc(sizeof(char *), 64);
	char *fpat_copy = NULL;

	if (tokpat == NULL)
		return (NULL);

	fpat_copy = _strdup(fpat);
	usep = strtok(fpat_copy, "=:");

	while (usep != NULL)
	{
		tokpat[count] = usep;
		count++;
		usep = strtok(NULL, "=:");
	}
	return (tokpat);
}
