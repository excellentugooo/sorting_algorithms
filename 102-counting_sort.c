#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 */
void counting_sort(int *array, size_t size)
{
	int i, max;
	int *counter = NULL, *dup = NULL;
	size_t j, temp, result = 0;


	if (array == NULL || size < 2)
		return;
	dup = malloc(sizeof(int) * size);
	if (dup == NULL)
		return;
	for (j = 0, max = 0; j < size; j++)
	{
		dup[j] = array[j];
		if (array[j] > max)
			max = array[j];
	}
	counter = malloc(sizeof(int) * (max + 1));
	if (counter == NULL)
	{
		free(dup);
		return;
	}
	for (i = 0; i <= max; i++)
		counter[i] = 0;
	for (j = 0; j < size; j++)
		counter[array[j]] += 1;
	for (i = 0; i <= max; i++)
	{
		temp = counter[i];
		counter[i] = result;
		result += temp;
	}
	for (j = 0; j < size; j++)
	{
		array[counter[dup[j]]] = dup[j];
		counter[dup[j]] += 1;
	}
	print_array(counter, max + 1);
	free(counter);
	free(dup);
}
