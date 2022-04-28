#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;

    test_start("Head NULL", "The variable head is NULL");
    head = NULL;
    print_listint(head);
    insert_node(&head, 27);
    printf("-----------------\n");
    printf("Inserted %d\n", 27);
    printf("-----------------\n");
    test_list_like_array(&head, (int[]){27}, 1);
    free_listint(head);
    test_end("Head NULL");

    test_start("Start with max", "The first value of the list is great that inserted");
    head = NULL;
    array_to_list(&head, (int[]){402}, 1);
    print_listint(head);
    insert_node(&head, 27);
    printf("-----------------\n");
    printf("Inserted %d\n", 27);
    printf("-----------------\n");
    test_list_like_array(&head, (int[]){27, 402}, 2);
    free_listint(head);
    test_end("Start with max");

    test_start("Start with min", "The first value of the list is less that inserted");
    head = NULL;
    array_to_list(&head, (int[]){5}, 1);
    print_listint(head);
    insert_node(&head, 27);
    printf("-----------------\n");
    printf("Inserted %d\n", 27);
    printf("-----------------\n");
    test_list_like_array(&head, (int[]){5, 27}, 2);
    free_listint(head);
    test_end("Start with min");

    test_start("Inset to start", "All values are great that value to insert");
    head = NULL;
    array_to_list(&head, (int[]){50, 51, 52, 53, 54, 98, 402, 1024}, 8);
    print_listint(head);
    insert_node(&head, 27);
    printf("-----------------\n");
    printf("Inserted %d\n", 27);
    printf("-----------------\n");
    test_list_like_array(&head, (int[]){27, 50, 51, 52, 53, 54, 98, 402, 1024}, 9);
    free_listint(head);
    test_end("Inset to start");

    test_start("Inset to end", "All values are less that value to insert");
    head = NULL;
    array_to_list(&head, (int[]){0, 1, 2, 3, 4, 8, 12, 24}, 8);
    print_listint(head);
    insert_node(&head, 27);
    printf("-----------------\n");
    printf("Inserted %d\n", 27);
    printf("-----------------\n");
    test_list_like_array(&head, (int[]){0, 1, 2, 3, 4, 8, 12, 24, 27}, 9);
    free_listint(head);
    test_end("Inset to end");

    test_start("Inset in the middler", "The value will be insert in the middler");
    head = NULL;
    array_to_list(&head, (int[]){0, 1, 2, 3, 4, 98, 402, 1024}, 8);
    print_listint(head);
    insert_node(&head, 27);
    printf("-----------------\n");
    printf("Inserted %d\n", 27);
    printf("-----------------\n");
    test_list_like_array(&head, (int[]){0, 1, 2, 3, 4, 27, 98, 402, 1024}, 9);
    free_listint(head);
    test_end("Inset in the middler");

    return (0);
}
