#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, k, tab = 1;
	int insert;

	if (array == NULL || size < 2)
		return;

	while (tab < size / 3)
		tab = tab * 3 + 1;

	while (tab > 0)
	{
		for (i = tab; i < size; i++)
		{
			insert = array[i];
			for (k = i; k >= tab && array[k - tab] > insert; k = k - tab)
				array[k] = array[k - tab];
			array[k] = insert;
		}
		tab = (tab - 1) / 3;
		print_array(array, size);
	}
}
