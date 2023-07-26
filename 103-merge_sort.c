#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * TDMerge - sorts and merges the sub arrays in source
 * @start: starting index (inclusive) for the left sub array
 * @middle: end index (exclusive) for the left sub array and
 * starting index (inclusive) for the right sub array
 * @end: end index (exclusive) for the right sub array
 * @dest: destination for data
 * @source: source of data
 *
 * Return: has no return value
 */
void TDMerge(size_t start, size_t middle, size_t end, int *dest, int *source)
{
	size_t x, y, z;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);
	x = start;
	y = middle;
	for (z = start; z < end; z++)
	{
		if (x < middle && (y >= end || source[x] <= source[y]))
		{
			dest[z] = source[x];
			x++;
		}
		else
		{
			dest[z] = source[y];
			y++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
 * TDSplitMerge - recursively splits the array and merges the sorted arrays
 * @start: starting index (inclusive)
 * @end: end index (exclusive)
 * @array: the array to sort
 * @copy: a copy of the array
 *
 * Return: has no return value
 */
void TDSplitMerge(size_t start, size_t end, int *array, int *copy)
{
	size_t middle;

	if (end - start < 2)
		return;
	middle = (start + end) / 2;
	TDSplitMerge(start, middle, array, copy);
	TDSplitMerge(middle, end, array, copy);
	TDMerge(start, middle, end, array, copy);
	for (middle = start; middle < end; middle++)
		copy[middle] = array[middle];
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: has no return value
 */
void merge_sort(int *array, size_t size)
{
	size_t x;
	int *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (x = 0; x < size; x++)
		copy[x] = array[x];
	TDSplitMerge(0, size, array, copy);
	free(copy);
}
