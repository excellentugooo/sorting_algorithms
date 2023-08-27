#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * part - finds the partition for the quicksort using the Hoare scheme
 * @array: array to sort
 * @low: lowest index of the partition to sort
 * @high: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of partition
 */
size_t part(int *array, ssize_t low, ssize_t high, size_t size)
{
	int swapped, point;

	point = array[high];
	while (low <= high)
	{
		while (array[low] < point)
			low++;
		while (array[high] > point)
			high--;
		if (low <= high)
		{
			if (low != high)
			{
				swapped = array[low];
				array[low] = array[high];
				array[high] = swapped;
				print_array(array, size);
			}
			low++;
			high--;
		}
	}
	return (high);
}

/**
 * quicksort - sorts a partition of an array of integers
 * @array: array to sort
 * @low: lowest index of the partition to sort
 * @high: highest index of the partition to sort
 * @size: size of the array
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t point;

	if (low < high)
	{
		point = part(array, low, high, size);
		quicksort(array, low, point, size);
		quicksort(array, point + 1, high, size);

	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
