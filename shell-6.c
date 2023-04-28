#include <unistd.h>

/**
 * _putchar - string of the output func
 * @var_chr: what to print
 *
 * Return: zero or null
 */
int _putchar(char var_chr)
{
	return (write(1, &var_chr, 1));
}
