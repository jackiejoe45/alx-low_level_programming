#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a dlistint_t list.
 * @h: Pointer to the head of the list.
 * Return: The number of nodes.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;
	const dlistint_t *temp = h;

	if (temp == NULL)
		return (count);

	/*
	 * while (temp->prev != NULL)
	 * temp = temp->prev;
	 */

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	return (count);
}

