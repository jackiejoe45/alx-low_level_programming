#include "lists.h"
/**
 * free_listint_safe - frees a listint_t linked list safely
 * @h: pointer to a pointer to the head of the linked list
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow = *h;
	listint_t *fast = *h;
	listint_t *temp = *h;
	size_t count = 0;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			while (*h != slow)
			{
				count++;
				*h = (*h)->next;
				free(temp);
			}
			count++;
			*h = (*h)->next;
			free(slow);
			slow = NULL;
			fast = NULL;
			break;
		}
	}
	while (*h != NULL)
	{
		count++;
		*h = (*h)->next;
		free(temp);
	}
	return (count);
}
