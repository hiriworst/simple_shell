#include "main.h"


/**
 * com_fun_struc - track command
 *
 * @command: where the com
 *
 * Return: succes or null
 **/
char *com_fun_struc(char *command)
{
	DIR *folder;
	struct dirent *entry;
	char *first_str, outputt, **str  = malloc(sizeof(char) * 1024);
	char **split = malloc(sizeof(char) * 1024);
	int i;

	while (*environ != NULL)
	{
		if (!(_strcmpdir(*environ, "PATH")))
		{
			*str = *environ;
			for (i = 0; i < 9; i++, split++, str++)
			{
				*split = strtok(*str, ":='PATH'");
				folder = opendir(*split);
				if (folder == NULL)
					perror("Unable to read directory");
				while ((entry = readdir(folder)))
				{
					first_str = entry->d_name;
					outputt = _strcmpdir(first_str, command);
					if (outputt == 0)
					{
						return (*split);
					}
					if (first_str == NULL)
					{
						perror("Error");
					}}}}
		environ++;
	}
	return ("Error: Not Found");
}
