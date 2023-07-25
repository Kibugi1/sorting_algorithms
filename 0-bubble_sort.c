#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers in ascending order
 * using the bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, n, new_n;
	int swap;

	if (array == NULL || size < 2)
		return;

	n = size;
	while (n > 0)
	{
		new_n = 0;
		for (x = 0; x < n - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				swap = array[x];
				array[x] = array[x + 1];
				array[x + 1] = swap;
				new_n = x + 1;
				print_array(array, size);
			}
		}
		n = new_n;
	}
}
