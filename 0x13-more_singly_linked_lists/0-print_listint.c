#include "lists.h"
/**
  * print_listint - prints all elements in list and returns count
  * @h: head of list
  * Return: number of items in list
  */
size_t print_listint(const listint_t *h)
{
	int count = 0;

	if (h == NULL)
		return (-1);

	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}
	return (count);
}

