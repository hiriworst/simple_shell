#include "main.h"
/**
 * _strcmpdir - compares strings to find dir.
 *
 * @fast_string: string.
 * @second_string: string.
 *
 * Return: if match and any other number if otherwise.
 **/
int _strcmpdir(char *fast_string, char *second_string)
{
	int i = 0;

	for (; (*second_string != '\0' && *fast_string != '\0') &&
			*fast_string == *second_string; fast_string++)
	{
		if (i == 3)
			break;
		i++;
		second_string++;
	}

	return (*fast_string - *second_string);
}
/**
 * charput - writes the character like putchar
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int charput(char c)
{
	return (write(1, &c, 1));
}

/**
 * place - similar to puts in C
 * @str: a pointer the integer we want to set to 402
 *
 * Return: int
 */
void place(char *str)
{
	while (*str != '\0')
	{
		charput(*str);
		str++;
	}
}

/**
 * _strlen - Len string.
 * @str: My string.
 * Return: Length.
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	return (i);
}

/**
 * str_concat - concatane strings.
 * @fast_string: string.
 * @second_string: second string.
 * Return: strings.
 */
char *str_concat(char *fast_string, char *second_string)
{
	char *a;
	int lenfast_string, lensecond_string, j, i, e;

	if (fast_string == NULL)
		fast_string = "";

	if (second_string == NULL)
		second_string = "";

	lenfast_string = _strlen(fast_string);

	lensecond_string = _strlen(second_string);

	a = malloc(((lenfast_string) +
				(lensecond_string) + 1) * sizeof(char));

	if (a == NULL)
		return (NULL);

	for (j = 0; j < lenfast_string; j++)
	{
		a[j] = fast_string[j];
	}

	for (i = lenfast_string, e = 0; e <= lensecond_string; i++, e++)
	{
		a[i] = second_string[e];
	}
	return (a);
}
