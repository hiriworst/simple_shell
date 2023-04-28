#include "main.h"

/**
 * _calloc - Allocates memory for array
 * @nmemb: Elements of array
 * @size: Size of array
 *
 * Return: Pinter to memory (x)
 **/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *x;
	unsigned int y;

	if (nmemb == 0 || size == 0)
		return (NULL);

	x = malloc(nmemb * size);

	if (x == NULL)
		return (NULL);

	for (y = 0 ; y < (nmemb * size) ; y++)
	{
		x[y] = 0;
	}
	return (x);
}
