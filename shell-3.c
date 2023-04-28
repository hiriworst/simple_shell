#include "main.h"

/**
 * str_concat - Concatenates 2 strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: NULL on error
 **/
char *str_concat(char *s1, char *s2)
{
	char *S;
	int x = 0;
	int y = 0;
	int z = 0;
	int w = 0;

	if (s1 != NULL)
	{
		for (x = 0 ; s1[x] != '\0' ; x++)
			;
	}
	if (s2 != NULL)
	{
		for (y = 0 ; s2[y] != '\0' ; y++)
			;
	}
		S = malloc(x + y + 1);

		if (S == NULL)
		{
			return (NULL);
		}
		for (z = 0 ; z < x + y ; z++)
		{
			if (z < x)
			{
				S[z] = s1[z];
			}
			else
			{
				S[z] = s2[w];
				w++;
			}
		}
		S[z] = '\0';
		return (S);
}
