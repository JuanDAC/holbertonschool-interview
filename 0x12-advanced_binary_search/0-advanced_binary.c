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

	if (size == 2 && (*array == value || *(array + 1) == value))
		return (*array == value ? index : index + 1);

	if (array[new_size - 1] >= value)
		return (_advanced_binary(array, size - (size / 2), value, index));

	return (_advanced_binary(
		array + new_size,
		size - new_size,
		value,
		index + new_size));
}
