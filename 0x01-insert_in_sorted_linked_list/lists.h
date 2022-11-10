#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint(listint_t *head);

listint_t *insert_node(listint_t **head, int number);

void test_start(char *name, char *description);
void test_end(char *name);
void array_to_list(listint_t **list, int array[], int size);
void test_list_like_array(listint_t **list, int *array, int size);
void free_list(listint_t *list);

int list_like_array(listint_t **list, int *array, int size);

#define COLOR_RED "\033[0;31m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_PURPLE "\033[0;35m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_CYAN "\033[0;36m"
#define COLOR_RESET "\033[0m"

#endif /* LISTS_H */
