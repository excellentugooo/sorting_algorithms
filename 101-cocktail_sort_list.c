#include "sort.h"
#include <stdio.h>

/**
 * swapped - swaps a node with the next node in the list
 * @list: double pointer to the beginning of the list
 * @node: node to swap
 */
void swapped(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	char swap = 1;
	listint_t *temp_node;

	if (list == NULL || *list == NULL)
		return;
	temp_node = *list;
	while (swap != 0)
	{
		swap = 0;
		while (temp_node->next != NULL)
		{
			if (temp_node->next->n < temp_node->n)
			{
				swapped(list, temp_node);
				swap = 1;
				print_list(*list);
			}
			else
				temp_node = temp_node->next;
		}
		if (swap == 0)
			break;
		swap = 0;
		while (temp_node->prev != NULL)
		{
			if (temp_node->prev->n > temp_node->n)
			{
				swapped(list, temp_node->prev);
				swap = 1;
				print_list(*list);
			}
			else
				temp_node = temp_node->prev;
		}
	}
}
