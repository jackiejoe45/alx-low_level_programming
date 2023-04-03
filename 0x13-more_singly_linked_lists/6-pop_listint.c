#include "lists.h"
/**
  * pop_listint - deletes the head node  and returns head node’s data (n).
  * @head: pointer to head of list
  * Return: head node's data
  */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (*head == NULL)
	{
		return (0);
	}

	temp = *head;
	data = temp->n;
	*head = (*head)->next;
	free(temp);

	return (data);
}
