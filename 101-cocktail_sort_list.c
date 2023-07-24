#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: The pointer to the head of the list
 * @node1: The first node to be swapped
 * @node2: The second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (node2->prev == NULL)
		*list = node2;

	print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: The pointer to the head of the list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped;
	listint_t *left = NULL;
	listint_t *right = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;

		for (current = *list; current->next != right; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
			}
		}

		right = (*list)->prev;

		if (!swapped)
			break;

		swapped = 0;

		for (current = right; current->prev != left; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
			}
		}

		left = (*list)->next;
	} while (swapped);
}
