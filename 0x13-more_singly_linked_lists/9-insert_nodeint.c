#include "lists.h"
/**
  * insert_nodeint_at_index - inserts node at a given position.
  * @head: pointer to head
  * @idx:  index where new node is added.
  * @n: data of new node
  * Return: addresss of the new node or NULL
  */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *node, *new_node;
	unsigned int i;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	node = *head;
	for (i = 0; node != NULL && i < idx - 1; i++)
		node = node->next;

	if (node == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = node->next;
	node->next = new_node;
	return (new_node);
}
