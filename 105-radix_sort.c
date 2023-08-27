#include "sort.h"

/**
 * pow - calculates a positive power of 10
 * @power: power of 10 to calculate
 *
 * Return: the power of 10
 */
unsigned int pow(unsigned int power)
{
	unsigned int i, answer;

	answer = 1;
	for (i = 0; i < power; i++)
		answer *= 10;
	return (answer);
}

/**
 * count_sort - sorts an array of integers in ascending order at a specific
 * digit location using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 * @digit: digit to sort by
 *
 * Return: 1 to keep sorting, 0 if not
 */
unsigned int count_sort(int *array, size_t size, unsigned int digit)
{
	int i, counter[10] = {0};
	int *dup = NULL;
	size_t j, temp, total = 0;
	unsigned int cp1, cp2, sortted = 0;

	cp2 = pow(digit - 1);
	cp1 = cp2 * 10;
	dup = malloc(sizeof(int) * size);
	if (dup == NULL)
		exit(1);
	for (j = 0; j < size; j++)
	{
		dup[j] = array[j];
		if (array[j] / cp1 != 0)
			sortted = 1;
	}
	for (i = 0; i < 10 ; i++)
		counter[i] = 0;
	for (j = 0; j < size; j++)
		counter[(array[j] % cp1) / cp2] += 1;
	for (i = 0; i < 10; i++)
	{
		temp = counter[i];
		counter[i] = total;
		total += temp;
	}
	for (j = 0; j < size; j++)
	{
		array[counter[(dup[j] % cp1) / cp2]] = dup[j];
		counter[(dup[j] % cp1) / cp2] += 1;
	}
	free(dup);
	return (sortted);
}

/**
 * radix_sort - sorts an array of integers in ascending order using
 * the Radix sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	unsigned int i, sortted = 1;

	if (array == NULL || size < 2)
		return;
	for (i = 1; sortted == 1; i++)
	{
		sortted = count_sort(array, size, i);
		print_array(array, size);
	}
}
