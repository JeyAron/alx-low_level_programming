#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * list_len - shows number of elements of a list
 * @h: pointer to the list_t list
 * Return: number of elements of a list
 */

size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
	count++;
	h = h->next;
	}
	return (count);
}
