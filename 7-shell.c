#include "main.h"

/**
 * free_memory_p - pointer
 *
 * @ptr: Pointer
 **/
void free_memory_p(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}

	ptr = NULL;
}

/**
 * free_memory_pp - double pointer
 *
 * @ptr:pointer to free
 **/
void free_memory_pp(void **ptr)
{
	void **ttmp;

	for (ttmp = ptr; *tmp != NULL; ttmp++)
		free_memory_p(*ttmp);

	free_memory_p(ptr);
}
