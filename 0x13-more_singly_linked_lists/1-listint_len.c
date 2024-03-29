#include "lists.h"

/**
 * listint_len - return the number of elements in a list
 * @h: head pointer
 * Return: number of nodes
 */

size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
	num++;
	h = h->next;
	}
	return (num);
}
