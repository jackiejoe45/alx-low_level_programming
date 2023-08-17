#include "lists.h"

/**
 * print_dlistint - Prints all the elements of a dlistint_t list.
 * @h: Pointer to the head of the list.
 * Return: The number of nodes.
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *temp = h;
	size_t count = 0;

	if (temp == NULL)
		return (count);

	/*
	 * while (temp->prev != NULL)
	 * temp = temp->prev;
	 */

	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
		count++;
	}

	return (count);
}

