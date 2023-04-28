#include "main.h"
/**
 * _strcmp - comp two strings one and two both in the func
 * @str_len1: string-lenth
 * @str_len2: second arg
 * Return: both strings
 */
int _strcmp(char *str_len1, char *str_len2)
{
	int get_in;
	int to_lup = 0;
	int outcome;

	for (get_in = 0; str_len1[get_in] != '\0'; get_in++, to_lup++)
	{
		outcome = str_len1[get_in] - str_len2[to_lup];

			if (outcome != 0)
				break;
	}
	return (outcome);

}
