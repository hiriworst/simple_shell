#include "main.h"

/**
 * _strcmp - compares two strings
 * @str_len: ptr
 * @str_ptr: ptr
 * Return: suc
 */

int _strcmp(char *str_len, char *str_ptr)
{
	while (*str_len && *str_ptr)
	{
		if (*str_len != *str_ptr)
		{
			return (*str_len - *str_ptr);
		}

		str_len++;
		str_ptr++;
	}
	return (0);
}

/**
 * _strcpy - func to cpy string
 * @ptr_where_to: pointer
 * @ptr_len: ponter
 * Return: @ptr_where_to
 */
char *_strcpy(char *ptr_where_to, char *ptr_len)
{
	char *tr = ptr_where_to;

	while (*ptr_len != '\0') 
	{
		*ptr_where_to = *ptr_len;
		ptr_where_to++;
		ptr_len++;
	}
	*ptr_where_to = '\0';
	return (ttyname_r);
}

/**
 * _split - split
 * @str: point to str
 * @take_out: 
 * Return: divided path
 */

char **_split(char *str, char *take_out)
{
	char *aux, **str_elem;
	int i = 0;

	aux = strtok(str, take_out);
	str_elem = (char **)_calloc(100, sizeof(char *));

	if (!str_elem)
	{
		free(str_elem);
		return (NULL);
	}

	while (aux)
	{
		str_elem[i] = aux;
		aux = strtok(NULL, take_out);
		i++;
	}
	return (str_elem);
}

/**
 * _strcat - function that concatenates two strings
 * @ptr_where_to: string
 * @ptr_len: string
 * Return: @ptr_where_to
 */

char *_strcat(char *ptr_where_to, char *ptr_len)
{
	int a, b;

	for (a = 0; ptr_where_to[a] != '\0'; a += 1)
	{}

	for (b = 0; ptr_len[b] != '\0'; b += 1)
	{
		ptr_where_to[a] = ptr_len[b];
		a++;
	}
	ptr_where_to[a] = '\0';
	return (ptr_where_to);
}

/**
 * _strlen - func len
 * @str: string
 * Return: result
 *
 */

int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}
