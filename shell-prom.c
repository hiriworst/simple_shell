#include "main.h"

/**
 * null_bytes - null bytes at given indes
 * @str: pointer string
 * @index: arg
 * Return: zero always
 */
void null_bytes(char *str, unsigned int index)
{
	str[index] = '\0';
}

/**
 * get_prompt - user inputs
 * Return: zero always
 */
void get_prompt(void)
{
	write(STDERR_FILENO, "$ ", 2);
}

/**
 * put_new_line - prints a newline
 * Return: Nothing
 */
void put_new_line(void)
{
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * init_manage - a function to handle singal integers
 * @sigint: signal input
 * Return: Nothing
 */
void init_manage(int sigint)
{
	(void)sigint;
	signal(SIGINT, init_manage);
	put_new_line();
	put_new_line();
	fflush(stdout);
}


