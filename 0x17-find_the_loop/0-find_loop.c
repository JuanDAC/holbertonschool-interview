#include "lists.h"

/**
 * _find_listint_loop - finds the loop in a linked list
 * @head: pointer to head of list
 * @slow: pointer to head of list
 * Return: address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *_find_listint_loop(listint_t *head, listint_t *slow)
{
	if (head == NULL)
		return (NULL);

	if (slow == NULL)
		return (NULL);

	if (slow == head)
		return (slow);

	return (_find_listint_loop(head, slow->next));
}
