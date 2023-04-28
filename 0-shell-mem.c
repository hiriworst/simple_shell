#include "main.h"

/**
 * _calloc - mem_allocation
 * @input_arr: number lists
 * @lenth: length
 * Return: pointer
 */

void *_calloc(unsigned int input_arr, unsigned int lenth)
{
	unsigned int digt_ind = 0;
	char *ptr = NULL;

	if (input_arr == 0 || lenth == 0)
		return (NULL);

	ptr = malloc(input_arr * lenth);

	if (ptr == NULL)
	{
		return (NULL);
	}

	for (; digt_ind < (input_arr * lenth); digt_ind++)
		ptr[digt_ind] = 0;

	return (ptr);
}
