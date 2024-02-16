#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap node
 * @list: list.
 * @tail: tail.
 * @shaker: shaker.
 * Return: 0
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev)
	{
		(*shaker)->prev->next = tmp;
	}
	else
	{
		*list = tmp;
	}

	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;

	if (tmp->next)
	{
		tmp->next->prev = *shaker;
	}
	else
	{
		*tail = *shaker;
	}

	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - Swap node.
 * @list: list.
 * @tail: tail.
 * @shaker: shaker.
 * Return: 0.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next)
	{
		(*shaker)->next->prev = tmp;
	}
	else
	{
		*tail = tmp;
	}

	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;

	if (tmp->prev)
	{
		tmp->prev->next = *shaker;
	}
	else
	{
		*list = *shaker;
	}

	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - Sort a list
 * @list: list.
 * Return: 0.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}

	for (tail = *list; tail->next; tail = tail->next)
	{
		continue;
	}

	while (!shaken_not_stirred)
	{
		shaken_not_stirred = true;

		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}

		for (shaker = shaker->prev; shaker != *list; shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
