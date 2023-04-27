#include "main.h"

/**
 * _realloc - mem-alocate
 *
 * @ptr: pointer
 * @old_size: size in bytes
 * @new_size: new size
 *
 * Return: success
 **/
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *s, *num_elem;
	unsigned int a;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		s = malloc(new_size);
		if (s == NULL)
			return (NULL);

		return (s);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	s = malloc(new_size);
	if (s == NULL)
		return (NULL);

	num_elem = ptr;
	for (a = 0; a < old_size; a++)
		s[a] = num_elem[a];

	free(ptr);

	return (s);
}

