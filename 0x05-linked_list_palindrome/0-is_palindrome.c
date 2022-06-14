#include "lists.h"

int palindrome(listint_t **string_left, listint_t **head)
{
    listint_t *move = NULL;
    listint_t *string_right = NULL;

    if (!head || (!*head && string_left))
        return (false);

    if (!*head)
        return (true);

    string_right = *head;

    if (!string_left)
        move = string_right, string_left = &move;

    if (palindrome(string_left, &(string_right->next)) == 0 && string_right->next != NULL)
        return (false);

    if ((*string_left)->n != string_right->n)
        return (false);

    if ((*string_left)->n == string_right->n)
        *string_left = (*string_left)->next;

    return (true);
}
