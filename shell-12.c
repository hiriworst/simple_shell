#include "main.h"

/**
 * find_env - func to get env varialbe
 * @environ: Environment variables
 **/
void find_env(char **environ)
{
	int digit_elem;

	for (digit_elem = 0 ; environ[digit_elem] ; digit_elem++)
	{
		_puts(environ[digit_elem]);
	}
}

