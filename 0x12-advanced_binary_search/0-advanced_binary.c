#include "search_algos.h"

void print_array(int *array, size_t size)
{
	if (size == 0)
	{
		printf("\n");
		return;
	}

	printf("%d", *array);
	if (size != 1)
		printf(", ");

	print_array(array + 1, size - 1);
}

int _advanced_binary(int *array, size_t size, int value, int index)
{
	size_t new_size = (size + 1) / 2;
	printf("Searching in array: ");
	print_array(array, size);
	if (size == 0)
		return (-1);

	if (size == 1)
		return (*array == value ? index : -1);

	if (array[new_size - 1] >= value)
		return (_advanced_binary(array, size - new_size, value, index));

	return (_advanced_binary(
		array + new_size,
		size - new_size,
		value,
		index + new_size));
}

#define advanced_binary(A, S, V) _advanced_binary(A, S, V, 0)

int main(void)
{
	int array[] = {
		0, 1, 2, 5, 5, 6, 6, 7, 8, 9};
	size_t size = sizeof(array) / sizeof(array[0]);

	printf("Found %d at index: %d\n\n", 8, advanced_binary(array, size, 8));
	printf("Found %d at index: %d\n\n", 5, advanced_binary(array, size, 5));
	printf("Found %d at index: %d\n", 999, advanced_binary(array, size, 999));
	return (EXIT_SUCCESS);
}