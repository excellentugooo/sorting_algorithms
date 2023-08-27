#include "sort.h"
#include <stdio.h>

/**
 * bit_compare - sort the values in a sub-array with respect to
 * the Bitonic sort algorithm
 * @ups: direction of sorting
 * @array: sub-array to sort
 * @size: size of the sub-array
 */
void bitonic_compare(char ups, int *array, size_t size)
{
	size_t i, distance;
	int swaps;

	distance = size / 2;
	for (i = 0; i < distance; i++)
	{
		if ((array[i] > array[i + distance]) == ups)
		{
			swaps = array[i];
			array[i] = array[i + distance];
			array[i + distance] = swaps;
		}
	}
}

/**
 * bit_merge - recursive function that merges two sub-arrays
 * @ups: direction of sorting
 * @array: sub-array to sort
 * @size: size of the sub-array
 */
void bit_merge(char ups, int *array, size_t size)
{
	if (size < 2)
		return;
	bit_compare(ups, array, size);
	bit_merge(ups, array, size / 2);
	bit_merge(ups, array + (size / 2), size / 2);
}

/**
 * bit_sort - recursive function using the Bitonic sort algorithm
 * @up: direction of sorting
 * @array: sub-array to sort
 * @size: size of the sub-array
 * @t: total size of the original array
 */
void bit_sort(char up, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	bit_sort(1, array, size / 2, t);
	bit_sort(0, array + (size / 2), size / 2, t);
	bit_merge(up, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);

}

/**
 * bitonic_sort - sorts an array of integers in ascending order using
 * the Bitonic sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bit_sort(1, array, size, size);
}
