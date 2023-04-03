#include "lists.h"
/**
  * delete_nodeint_at_index - deletes node at an index given
  * @head: pointer to head
  * @index: index of the node
  * Return: 1 (Success) or -1 (Failure)
  */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	 listint_t *temp;
	listint_t *node;
	unsigned int i;


	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	node = *head;
	for (i = 0; node != NULL && i < index - 1; i++)
		node = node->next;

	if (node == NULL || node->next == NULL)
		return (-1);

	temp = node->next;
	node->next = temp->next;
	free(temp);
	return (1);

}
