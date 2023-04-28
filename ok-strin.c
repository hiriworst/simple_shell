#include "main.h"
/**
 * _strtok - ffjkdjksfkjkhat parses string
 *@str: string to parsesfkjk
 *@token: delimitersfhjhfj
 *Return: 0
 */
int _strtok(char *str, const char *token)
{
	char str[] = "";
	char *token = strtok(str, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}
