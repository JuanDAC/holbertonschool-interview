#include "lists.h"

listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow = head;
    if (head == NULL)
        return (NULL);

    while (slow != NULL)
    {
        slow = slow->next;
        if (slow == head)
            return (slow);
    }

    return (NULL);
}