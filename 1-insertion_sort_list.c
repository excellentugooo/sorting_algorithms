#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp_node, *next_node;

	if (list == NULL || *list == NULL)
		return;

	temp_node = (*list)->next;
	while (temp_node != NULL)
	{
		next_node = temp_node->next;
		while (temp_node->prev != NULL && temp_node->prev->n > temp_node->n)
		{
			temp_node->prev->next = temp_node->next;
			if (temp_node->next != NULL)
				temp_node->next->prev = temp_node->prev;
			temp_node->next = temp_node->prev;
			temp_node->prev = temp_node->next->prev;
			temp_node->next->prev = temp_node;
			if (temp_node->prev == NULL)
				*list = temp_node;
			else
				temp_node->prev->next = temp_node;
			print_list(*list);
		}
		temp_node = next_node;
	}
}
