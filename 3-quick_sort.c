#include "sort.h"

/**
 * seperate - finds the partition for the quicksort using the Lomuto scheme
 * @array: array to sort
 * @low: lowest index of the partition to sort
 * @high: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
 */
size_t seperate(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t i, j;
	int temp, point;

	point = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < point)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
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
		point = seperate(array, low, high, size);
		quicksort(array, low, point - 1, size);
		quicksort(array, point + 1, high, size);

	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: The array to sort
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
