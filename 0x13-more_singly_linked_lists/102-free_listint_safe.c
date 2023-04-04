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

	if (h == NULL)
                return (0);

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = *h;
			while (slow != fast)
			{
				temp = slow;
				slow = slow->next;
				free(temp);
				count++;
			}
			temp = slow;
			slow = slow->next;
			free(temp);
			count++;
			break;
		}
	}

	while (*h != NULL)
	{
		temp = *h;
		*h = (*h)->next;
		free(temp);
		count++;
	}
	*h = NULL;
	return (count);
}
