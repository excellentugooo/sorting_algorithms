#include "deck.h"

/**
 * get_value - gets the relative value of a card from it's string value
 * @str: string value of the card
 *
 * Return: relative value of the card (0 through 12)
 */
int get_value(const char *str)
{
	int i;
	char *card[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
	{
		if (strcmp(str, card[i]) == 0)
		{
			return (i);
		}
	}
	exit(1);
}

/**
 * swap_node - swaps a node with the next node in the list
 * @head: double pointer to the beginning of the list
 * @node: node to swap
 */
void swap_node(deck_node_t **head, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*head = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * sort_deck - sorts a linked list deck of cards
 * @deck: double pointer to the deck to sort
 */
void sort_deck(deck_node_t **deck)
{
	char swap = 1, card1, card2;
	deck_node_t *current;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	current = *deck;
	while (swap != 0)
	{
		swap = 0;
		while (current->next != NULL)
		{
			card1 = get_value(current->card->value) + 13 * current->card->kind;
			card2 = get_value(current->next->card->value) + 13 * current->next->card->kind;
			if (card1 > card2)
			{
				swap_node(deck, current);
				swap = 1;
			}
			else
				current = current->next;
		}
		if (swap == 0)
			break;
		swap = 0;
		while (current->prev != NULL)
		{
			card1 = get_value(current->card->value) + 13 * current->card->kind;
			card2 = get_value(current->prev->card->value) + 13 * current->prev->card->kind;
			if (card1 < card2)
			{
				swap_node(deck, current->prev);
				swap = 1;
			}
			else
				current = current->prev;
		}
	}
}
