#include "lists.h"

/**
 * insert_node - insert a node in order
 * @head: head of like list node
 * @number: number of node inserted
 * Return: listint_t*
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = NULL;
	/*
	 * insert_node:: (NULL, number) -> NULL
	 */
	if (!head)
	{
		return (NULL);
	}
	/*
	 * insert_node:: (*NULL, number) -> NULL
	 */
	if (!*head)
	{
		node = malloc(sizeof(listint_t)), node->next = NULL, node->n = number;
		*head = node;
		return (node);
	}
	/*
	 * insert_node:: (*{ n } : *NULL, number) | n > number -> *listint_t
	 */
	if ((*head)->n > number)
	{
		node = malloc(sizeof(listint_t)), node->next = NULL, node->n = number;
		node->next = (*head), *head = node;
		return (node);
	}
	/*
	 * insert_node:: (_: *{ n } : list, number) | n > number -> *listint_t
	 */
	if ((*head)->next && (*head)->next->n > number)
	{
		node = malloc(sizeof(listint_t)), node->next = NULL, node->n = number;
		node->next = (*head)->next, (*head)->next = node;
		return (node);
	}
	/*
	 * insert_node:: (_ : [*listint_t], number)
	 *               -> insert_node(listint_t, number)
	 */
	return (insert_node(&((*head)->next), number));
}

/**
 * add_node_begin - Add a new node to the beginning of a
 * double circular linked list
 * Arguments:
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Returns: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *node = NULL;

	/*
	 * add_node_begin:: (NULL, str) -> NULL
	 */
	if (!list)
	{
		return (NULL);
	}
	/*
	 * add_node_begin:: (*NULL, str) -> NULL
	 */
	if (!*list)
	{
		node = malloc(sizeof(List)), node->str = strdup(str);
		node->prev = node, node->next = node;
		*list = node;
		return (node);
	}
	/*
	 * add_node_begin:: (*{ str } : *NULL, str) -> *list
	 */
	if (!(*list)->next)
	{
		node = malloc(sizeof(List)), node->str = strdup(str);
		node->prev = *list, node->next = *list;
		(*list)->next = node, (*list)->prev = node;
		return (node);
	}
	/*
	 * add_node_begin:: (_ : [*list], str)
	 *               -> add_node_begin(list, str)
	 */
	return (add_node_begin(&((*list)->next), str));
}
