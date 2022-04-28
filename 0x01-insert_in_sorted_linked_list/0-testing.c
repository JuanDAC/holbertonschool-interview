#include "lists.h"

/**
 * test_start - init a test
 * 
 * @name: name of the test
 * @description: description of the test
 * 
 * Return: Always void
 */
void test_start(char *name, char *description)
{
    static int number = 0;
    char *color = number % 2 ? COLOR_YELLOW : COLOR_PURPLE;
    printf(
        "\n%s[%d]===============>%s (%s%s%s) [%s]\n",
        color,
        ++number,
        COLOR_RESET,
        COLOR_CYAN,
        name,
        COLOR_RESET,
        description);
}

/**
 * test_end - end a test
 * 
 * @name: name od test
 */
void test_end(char *name)
{
    static int number = 0;
    char *color = number % 2 ? COLOR_YELLOW : COLOR_PURPLE;
    printf(
        "\n%s[%d]<===============%s (%s%s%s)\n",
        color,
        ++number,
        COLOR_RESET,
        COLOR_CYAN,
        name,
        COLOR_RESET);
}

/**
 * array_to_list - list from a array
 * 
 * @list: list of elements from array
 * @array: array of elements to insert into list
 * @size: size of the array
 */
void array_to_list(listint_t **list, int *array, int size)
{
    /*
     * array_to_list:: (*listint_t, [int], 0) -> void
     */
    if (size == 0)
    {
        return;
    }

    /*
     * array_to_list:: (*listint_t, [int], 0) -> void
     */
    add_nodeint_end(list, *array);

    /*
     * array_to_list:: (*listint_t, [int], 0) -> void
     */
    array_to_list(list, array + 1, size - 1);
}

/**
 * list_like_array - valid if list is like a array
 * 
 * @list: list of elements from array
 * @array: array of elements to insert into list
 * @size: size of the array
 */
int list_like_array(listint_t **list, int *array, int size)
{
    /*
     * list_like_array:: (*NULL, array, size) -> true
     */
    if ((!list || !*list) && size != 0)
    {
        return 0;
    }

    /*
     * list_like_array:: (*NULL, array, size) -> true
     */
    if (list && *list && size == 0)
    {
        return 0;
    }

    /*
     * list_like_array:: (NULL, [], 0) -> true
     */
    if ((!list || !*list) && size == 0)
    {
        return 1;
    }

    /*
     * list_like_array:: (*NULL, [], 0) -> true
     */
    if (size == 0 && !*list)
    {
        return 1;
    }

    /*
     * list_like_array:: (*{n} : list, number : array, size) 
     *                   | n == number -> list_like_array(list, array, size - 1)
     */
    if ((*list)->n == *array)
    {
        return list_like_array(&((*list)->next), array + 1, size - 1);
    }

    /*
     * list_like_array:: (*listint_t, array, size) -> false
     */
    return 0;
}

/**
 * test_list_like_array - test if list is like a array
 * 
 * @list: list of elements from array
 * @array: array of elements to insert into list
 * @size: size of the array
 */
void test_list_like_array(listint_t **list, int *array, int size)
{
    if (list_like_array(list, array, size))
    {
        printf("%sOK%s\n", COLOR_GREEN, COLOR_RESET);
    }
    else
    {
        printf(COLOR_RED);
        print_listint(*list);
        printf(COLOR_RESET);
    }

}

/**
 * free_list - free a list
 *
 * @list: free to list
 */
void free_list(listint_t *list)
{
    /*
     * free_list:: NULL -> void
     */
    if (list == NULL)
    {
        return;
    }

    /*
     * free_list:: {next} -> free_list(next)
     */
    free_list(list->next);

    /*
     * free_list:: listint_t -> void
     */
    free(list);
}