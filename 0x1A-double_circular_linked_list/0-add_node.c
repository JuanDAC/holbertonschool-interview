
#include "list.h"

/**
 * Add a new node to the end of a double circular linked list:
 * Arguments:
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Returns: Address of the new node, or NULL on failure
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
    /*
     * add_node_end:: (*NULL, str) -> NULL
     */
    if (!*list)
    {
        node = malloc(sizeof(List)), node->str = strdup(str);
        node->prev = node, node->next = node;
        *list = node;
        return (node);
    }
    /*
     * add_node_end:: (*{ str } : *NULL, str) -> *list
     */
    if (!(*list)->next)
    {
        node = malloc(sizeof(List)), node->str = strdup(str);
        node->prev = *list, node->next = *list;
        (*list)->next = node, (*list)->prev = node;
        return (node);
    }
    /*
     * add_node_end:: (_ : [*list], str)
     *               -> add_node_end(list, str)
     */
    return (add_node_end(&((*list)->next), str));
}

/**
 * add_node_begin - Add a new node to the beginning of
 * a double circular linked list
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

    node = malloc(sizeof(List)), node->str = strdup(str);
    if (!node)
    {
        return (NULL);
    }
    node->prev = *list, node->next = *list;
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