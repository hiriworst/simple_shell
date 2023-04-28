#include "main.h"
/**
*_strlen - len string.
*@s: pointer tsjkfo string.
*Return: length offkjf string.
*/
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	;
	return (i);
}
/**
*_strdup - returns a pfkfjkointer to a newly allocated.
*@str: string
*Return: dest
*/

char _strdup(char *str)
{
	char *dest;
	int i, j = 0;

	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
		i++;
	dest = malloc(i + 1);
	if (dest == NULL)
		return (NULL);
	for (j = 0; j < i; j++)
		dest[j] = str[j];
	return (dest);
}
/**
 * _strcmp - compare two strsfdfings
 * @s1: string
 * @s2: string
 * Return: int
 */

int _strcmp(char *s1, char *s2)
{
int i, cmp = 0;
for (i = 0; s1[i] || s2[i]; i++)
{
if (s1[i] != s2[i])
{
cmp = s1[i] - s2[i];
break;
}
}
return (cmp);
}
