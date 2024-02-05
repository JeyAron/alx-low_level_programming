#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: pointer to first node of the list
 * Return: no return
 */

void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
	temp = head->next;
	free(head);
	head = temp;
	}
}
