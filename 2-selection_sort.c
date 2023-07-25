#include "sort.h"

/**
 * selection_sort - s function that sorts an array of integers in ascending
 * order using the selection sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t x, j, min;
	int swap;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		min = x;
		for (j = x + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (x != min)
		{
			swap = array[x];
			array[x] = array[min];
			array[min] = swap;
			print_array(array, size);
		}
	}
}
