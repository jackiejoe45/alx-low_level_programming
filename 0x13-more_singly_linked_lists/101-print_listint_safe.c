#include "lists.h"
/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the linked list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head;
	const listint_t *fast = head;
	size_t count = 0;

	while (fast != NULL && fast->next != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			printf("[%p] %d\n", (void *)slow, slow->n);
			count++;
			break;
		}
	}
	while (head != slow)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;
		head = head->next;
	}
	printf("[%p] %d\n", (void *)head, head->n);
	count++;
	return (count);
}
