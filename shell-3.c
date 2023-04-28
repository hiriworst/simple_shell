#include "main.h"

/**
 * str_concat - put two strings together
 * @string_one:  one line of string
 * @string_two: other line of str
 *
 * Return: zero or null
 **/
char *str_concat(char *string_one, char *string_two)
{
	char *S;
	int x = 0;
	int y = 0;
	int z = 0;
	int w = 0;

	if (string_one != NULL)
	{
		for (x = 0 ; string_one[x] != '\0' ; x++)
			;
	}
	if (string_two != NULL)
	{
		for (y = 0 ; string_two[y] != '\0' ; y++)
			;
	}
		S = malloc(x + y + 1);

		if (S == NULL)
			return (NULL);
		for (z = 0 ; z < x + y ; z++)
		{
			if (z < x)
			{
				S[z] = string_one[z];
			}
			else
			{
				S[z] = string_two[w];
				w++;
			}
		}
		S[z] = '\0';
		return (S);
}
