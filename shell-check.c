#include "main.h"

/**
 * prompt - promth user to type anything
 **/
void prompt(void)
{
	for (;;)
	{
		char *input_wrd = NULL, **environ;
		pid_t child_pid;
		int result, lenbuf;
		size_t bufsize = 0;

		place("$ ");
		lenbuf = getline(&input_wrd, &bufsize, stdin);
		if (lenbuf == -1)
			exit(98);
		if (differentiate_func(input_wrd, "exit") == 0)
		exit(0);
		if (compareEnv(input_wrd, "env") == 0)
		{
			while (*environ != NULL)
			{
				if (!(_strcmpdir(*environ, "USER")) ||
				!(_strcmpdir(*environ, "LANGUAGE")) ||
						!(_strcmpdir(*environ, "SESSION")) ||
						!(_strcmpdir(*environ, "COMPIZ_CONFIG_PROFILE")) ||
						!(_strcmpdir(*environ, "SHLV")) || !(_strcmpdir(*environ, "HOME")) ||
						!(_strcmpdir(*environ, "C_IS")) ||
						!(_strcmpdir(*environ, "DESKTOP_SESSION")) ||
						!(_strcmpdir(*environ, "LOGNAME")) || !(_strcmpdir(*environ, "TERM")) ||
						!(_strcmpdir(*environ, "PATH")))
						{
					place(*environ), place("\n");
					}
					environ++;
					}}
		child_pid = fork();
		if (child_pid < 0)
		perror("Error");
		if (child_pid == 0)
			search_str(input_wrd);
		else
		wait(&result);
	}}
