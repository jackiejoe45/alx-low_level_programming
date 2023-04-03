#include "lists.h"
/**
  * listint_len - returns number of elements in a list
  * @h:head of list
  * Return: nymber of elements
  */
size_t listint_len(const listint_t *h)
{
	int count = 0;

	while (h->next != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}

