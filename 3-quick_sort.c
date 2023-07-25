#include "sort.h"
#include <stdio.h>

/**
 * partition - a function that finds the partition for the quicksort using the
 * Lomuto scheme
 * @array: array to sort
 * @low: lowest index of the partition to sort
 * @high: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
 */

size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t x, j;
	int swap, pivot;

	pivot = array[high];
	x = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			x++;
			if (x != j)
			{
				swap = array[x];
				array[x] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[x + 1])
	{
		swap = array[x + 1];
		array[x + 1] = array[high];
		array[high] = swap;
		print_array(array, size);
	}
	return (x + 1);
}

/**
 * quicksort - a function that sorts a partition of an array of integers
 * @array: array to be sorted
 * @low: lowest index of the partition to sort
 * @high: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: void
 */

void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);

	}
}

/**
 * quick_sort - a function that sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
