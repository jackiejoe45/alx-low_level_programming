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
	int loop_detected = 0;
	hash_table_t *ht;
	hash_node_t *node;
	
	ht = hash_table_create(1024);
	if (ht == NULL)
		exit(1);
	
	while (fast != NULL && fast->next != NULL)
	{
		if (hash_table_set(ht, (void *)slow, "1") == 0)
		{
			printf("[%p] %d\n", (void *)slow, slow->n);
			count++;
		}
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			loop_detected = 1;
			break;
		}
	}
	
	if (loop_detected)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
		for (node = ht->array[hash_table_get_node_index(ht, (void *)slow)];
				node != NULL; node = node->next)
		{
			printf("[%p] %d\n", node->key, ((listint_t *)node->key)->n);
			count++;
			if (node->key == slow)
				break;
		}
		printf("...\n");
	}
	for (; head != NULL && !loop_detected; head = head->next)
	{
		if (hash_table_set(ht, (void *)head, "1") == 0)
        {
            printf("[%p] %d\n", (void *)head, head->n);
            count++;
        }
	}
	hash_table_delete(ht);
	return (count);
}
