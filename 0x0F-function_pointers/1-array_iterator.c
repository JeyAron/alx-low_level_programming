#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - iterates the array elements
 * @array: the array
 * @size: the size of array
 * @action: functon pointer to array
 * Return: void
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action  == NULL)
	return;
	for (i = 0; i < size; i++)
	{
	action(array[i]);
	}
}
