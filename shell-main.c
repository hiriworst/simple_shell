#include "main.h"

/**
 * main - function main
 * @ac: first arg
 * @av: second arg
 * Return: zero.
 **/
int main(int ac, char **av)
{
	(void)av;
	(void)ac;

	signal(SIGINT, controlC);
	prompt();
	return (0);
}
