#include "lists.h"
/**
 * free_listint_safe - frees a listint_t list
 * @h: pointer to the head of the list
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *current, *tmp;

	if (h == NULL)
		return (0);
	current = *h;
	while (current != NULL)
	{
		size++;
		if (current < current->next)
		{
			printf("-> [%p] %d\n", (void *)current, current->n);
			break;
		}
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*h = NULL;
	return (size);
}
