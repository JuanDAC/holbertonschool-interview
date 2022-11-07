#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * print_list - Print informations about each element of a list
 *
 * @list: A pointer to the head of the linkd list
 *
 * Return: void
 */
void print_list(List *list)
{
	List *tmp;

	tmp = list;
	while (tmp)
	{
		printf("%s\n", tmp->str);
		printf("\t->prev: %s\n", tmp->prev ? tmp->prev->str : "NULL");
		printf("\t->next: %s\n", tmp->next ? tmp->next->str : "NULL");
		tmp = tmp->next;
		if (tmp == list)
			break;
	}
}

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	List *list, *node;

	list = NULL;
	add_node_end(&list, "One fish");
	node = add_node_end(&list, "Two fish");
	print_list(list);
	print_list(node);

	return (0);
}
