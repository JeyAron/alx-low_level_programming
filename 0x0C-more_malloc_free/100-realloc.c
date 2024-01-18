#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _realloc - reallocate the memory
 * @ptr: former pointer to the old memory allocated by malloc
 * @old_size: old size allocated by malloc in the heap
 * @new_size: new size allocated by _relloc
 * Return: pointer to the newly allocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *nptr;
	unsigned int i;

	if (new_size == old_size)
	return (ptr);

	if (ptr == NULL)
	{
	nptr = malloc(new_size);

	if (nptr == NULL)
	return (NULL);

	return (nptr);
	}
	else
	{
	if (new_size == 0)
	{
	free(ptr);
	return (NULL);
	}
	}
	nptr = malloc(new_size);
	
	if (nptr == NULL)
	return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
	{
	nptr[i] = ((char *) ptr)[i];
	}

	free(ptr);
	return (nptr);
}
