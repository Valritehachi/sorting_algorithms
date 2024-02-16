#include "sort.h"

/**
 * swap_nodes - Swap nodes.
 * @list: list.
 * @node1: node 1.
 * @node2: node 2.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
	}
	else
	{
		*list = node2;
	}

	if (node2->next != NULL)
	{
		node2->next->prev = node1;
	}

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - ...
 * @list: list.
 * Return: 0.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		insert = current->prev;
		while (insert != NULL && current->n < insert->n)
		{
			swap_nodes(list, insert, current);
			print_list((const listint_t *)*list);
			insert = current->prev;
		}
	}
}

