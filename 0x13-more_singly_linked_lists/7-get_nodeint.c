#include "lists.h"
/**
  * get_nodeint_at_index - returns the nth node of a listint_t linked list.
  * @head: pointer to head of list
  * @index: index of the node
  * Return: nth Node
  */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *node;
	unsigned int i;

	node = head;
	for (i = 0; node != NULL && i < index; i++)
	{
		node = node->next;
	}
	return (node);
}
