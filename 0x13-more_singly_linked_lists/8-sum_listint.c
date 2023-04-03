#include "lists.h"
/**
  * sum_listint -  returns the sum of all the data of a linked list.
  * @head: pointer to head
  * Return:  sum of node data
  */
int sum_listint(listint_t *head)
{
	listint_t *node;
	int sum = 0;

	node = head;
	while (node != NULL)
	{
		sum += node->n;
		node = node->next;
	}
	return (sum);
}

