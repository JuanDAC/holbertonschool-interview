
#include "list.h"

/**
 * add_node_end - Add a new node to the end of
 * a double circular linked list:
 * Arguments:
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *node = NULL;

	/*
	 * add_node_end:: (NULL, str) -> NULL
	 */
	if (!list)
	{
		return (NULL);
	}
	node = malloc(sizeof(List));
	if (!node)
	{
		return (NULL);
	}
	node->str = strdup(str), node->prev = NULL, node->next = NULL;
	if (!node->str)
	{
		free(node);
		return (NULL);
	}
	/*
	 * add_node_end:: (*NULL, str) -> NULL
	 */
	if (!*list)
	{
		node->prev = node, node->next = node;
		*list = node;
		return (node);
	}
	/*
	 * add_node_end:: (*{ str } : *NULL, str) -> *list
	 */
	(*list)->prev->next = node, node->prev = (*list)->prev;
	(*list)->prev = node, node->next = *list;
	return (node);
}

/**
 * add_node_begin - Add a new node to the beginning of
 * a double circular linked list
 * Arguments:
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
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

	node = malloc(sizeof(List));
	if (!node)
	{
		return (NULL);
	}
	node->prev = NULL, node->next = NULL, node->str = strdup(str);
	if (!node->str)
	{
		free(node);
		return (NULL);
	}
	if (*list)
	{
		node->prev = (*list)->prev, node->next = (*list);
		(*list)->prev->next = node, (*list)->prev = node;
	}
	/*
	 * add_node_begin:: (*NULL , str) -> *list
	 */
	if (!*list)
	{
		node->prev = node, node->next = node;
	}
	*list = node;
	return (node);
}
