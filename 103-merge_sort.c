#include "sort.h"

/**
 * Merge - sorts and merges the sub arrays in source
 * @start: starting index (inclusive) for the left sub array
 * @mid: end index (exclusive) for the left sub array and
 * starting index (inclusive) for the right sub array
 * @end: end index (exclusive) for the right sub array
 * @final: destination for data
 * @source: source of data
 */
void Merge(size_t start, size_t mid, size_t end, int *final, int *source)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, mid - start);
	printf("[right]: ");
	print_array(source + mid, end - mid);
	i = start;
	j = mid;
	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || source[i] <= source[j]))
		{
			final[k] = source[i];
			i++;
		}
		else
		{
			final[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(final + start, end - start);
}

/**
 * Split - recursively splits the array and merges the sorted arrays
 * @start: starting index (inclusive)
 * @end: end index (exclusive)
 * @array: the array to sort
 * @dup: a copy of the array
 */
void Split(size_t start, size_t end, int *array, int *dup)
{
	size_t mid;

	if (end - start < 2)
		return;
	mid = (start + end) / 2;
	Split(start, mid, array, dup);
	Split(mid, end, array, dup);
	Merge(start, mid, end, array, dup);
	for (mid = start; mid < end; mid++)
		dup[mid] = array[mid];
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *dup;

	if (array == NULL || size < 2)
		return;
	dup = malloc(sizeof(int) * size);
	if (dup == NULL)
		return;
	for (i = 0; i < size; i++)
		dup[i] = array[i];
	Split(0, size, array, dup);
	free(dup);
}
