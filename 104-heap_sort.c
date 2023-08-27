#include "sort.h"

/**
 * sift - fixes a heap
 * @array: the heap to fix
 * @start: the root of the heap
 * @end: the last index of the heap
 * @size: size of the array
 */
void sift(int *array, size_t start, size_t end, size_t size)
{
	size_t left_side, right_side, swap;
	int temp;

	while ((left_side = (2 * start) + 1) <= end)
	{
		swap = start;
		right_side = left_side + 1;
		if (array[swap] < array[left_side])
			swap = left_side;
		if (right_side <= end && array[swap] < array[right_side])
			swap = right_side;
		if (swap == start)
			return;
		temp = array[start];
		array[start] = array[swap];
		array[swap] = temp;
		print_array(array, size);
		start = swap;
	}
}

/**
 * make - makes a heap from an unsorted array
 * @array: array to turn into a heap
 * @size: size of the array
 */
void make(int *array, size_t size)
{
	size_t source;

	for (source = ((size - 1) - 1) / 2; 1; source--)
	{
		sift_down(array, source, size - 1, size);
		if (source == 0)
			break;
	}
}

/**
 * heap_sort - sorts an array of ints in ascending order w/ the Heap sort algo
 * @array: array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;

	if (array == NULL || size < 2)
		return;
	make(array, size);
	end = size - 1;
	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		end--;
		sift(array, 0, end, size);
	}
}
