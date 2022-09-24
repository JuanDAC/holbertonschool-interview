#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to head of list
 * @turtle: pointer to turtle
 * @hare: pointer to hare
 * @init: flag to initialize turtle and hare
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int _check_cycle(listint_t *list, listint_t *turtle,
				 listint_t *hare, int init)
{
	if (list == NULL)
		return (0);

	if (!init && hare == turtle)
		return (1);

	if (init)
	{
		turtle = list;
		hare = list;
		init = 0;
	}

	if (hare == NULL || turtle == NULL)
		return (0);

	return (_check_cycle(
		list,
		turtle->next,
		hare->next ? hare->next->next : hare->next,
		init));
}
