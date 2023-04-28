#include "main.h"
/**
 * _strcmp - comp two strings one and two both in the func
 * @string_length_one: string-lenth
 * @string_lenth_two: second arg
 * Return: both strings
 */
int _strcmp(char *string_length_one, char *string_lenth_two)
{
	int loop_through;
	int other_loop_through = 0;
	int outcome;

	for (loop_through = 0; string_length_one[loop_through] != '\0'; loop_through++, other_loop_through++)
	{
		outcome = string_length_one[loop_through] - string_lenth_two[other_loop_through];

			if (outcome != 0)
				break;
	}
	return (outcome);

}
