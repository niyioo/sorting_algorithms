#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *sorted, *temp;

	current = (*list)->next;
	while (current != NULL)
	{
		sorted = current->prev;
		temp = current;

		while (sorted != NULL && sorted->n > temp->n)
		{
			if (sorted->prev != NULL)
				sorted->prev->next = temp;

			temp->prev = sorted->prev;
			sorted->prev = temp;
			sorted->next = temp->next;

			if (temp->next != NULL)
				temp->next->prev = sorted;

			temp->next = sorted;

			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);

			sorted = temp->prev;
		}

		current = current->next;
	}
}
