#include "main.h"

/**
 * _calloc - memory holder
 * @num_elem_data: first arg
 * @size: second ar
 *
 * Return: ptr to calloc
 **/
void *_calloc(unsigned int num_elem_data, unsigned int size)
{
	char *x;
	unsigned int data_var;

	if (num_elem_data == 0 || size == 0)
	{
		return (NULL);
	}

	x = malloc(num_elem_data * size);

	if (x == NULL)
	{
		return (NULL);
	}

	for (data_var = 0 ; data_var < (num_elem_data * size) ; data_var++)
	{
		x[data_var] = 0;
	}
	return (x);
}
