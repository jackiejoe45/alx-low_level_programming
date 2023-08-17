#include <stdlib.h>
#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data of a dlistint_t list.
 * @head: Pointer to the head of the list.
 * Return: The sum of all data, or 0 if the list is empty.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *temp = head;

	/*
	 *  while (temp->prev != NULL)
	 * temp = temp->prev;
	 */

	while (temp != NULL)
	{
		sum += temp->data;
		temp = temp->next;
	}

	return (sum);
}

