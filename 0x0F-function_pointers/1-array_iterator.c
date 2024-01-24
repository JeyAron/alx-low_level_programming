#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - iterates the array
 * @array - the array
 * @size: size of array
 * @action: pointer to the function to be executed
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array == NULL || action == NULL)
	return;

	while (size-- > 0)
	{
	action(*array);
	array++;
	}
}
