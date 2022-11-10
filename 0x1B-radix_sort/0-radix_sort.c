

/**
 * radix_sort - sorts an array of integers in ascending
 *              order using the LSD Radix sort algorithm
 * @array: array to sort.
 * @size: size of the array.
 */
void radix_sort(int *array, size_t size)
{
    int i = 0, j = 0, k = 0, max = 0, exp = 0;
    int *output = NULL, *count = NULL;

    if (array == NULL || size < 2)
        return;

    max = array[0];
    for (i = 1; i < (int)size; i++)
        if (array[i] > max)
            max = array[i];

    output = malloc(sizeof(int) * size);
    if (output == NULL)
        return;

    count = malloc(sizeof(int) * 10);
    if (count == NULL)
    {
        free(output);
        return;
    }

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        for (i = 0; i < 10; i++)
            count[i] = 0;

        for (i = 0; i < (int)size; i++)
            count[(array[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = (int)size - 1; i >= 0; i--)
        {
            output[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
        }

        for (i = 0; i < (int)size; i++)
            array[i] = output[i];

        print_array(array, size);
    }

    free(count);
    free(output);
}
