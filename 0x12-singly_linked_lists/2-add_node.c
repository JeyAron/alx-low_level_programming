#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds new node at the beginning of list
 * @head: double pointer to list_t list
 * @str: string to add in the node
 * Return: address of new element, or NULL if fails
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int len = 0;

	while (str[len])
	len++;

	new = malloc(sizeof(list_t));
	if (!new)
	return (NULL);

	new->next = (*head);
	new->str = strdup(str);
	new->len = len;
	(*head) = new;

	return (*head);
}
