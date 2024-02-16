#include "sort.h"

/**
 * swap_elements - Swap elements.
 * @array: array.
 * @idx1: Index.
 * @idx2: Index.
 * Return: 0.
 */
void swap_elements(int *array, size_t idx1, size_t idx2)
{
	int tmp = array[idx1];

	array[idx1] = array[idx2];
	array[idx2] = tmp;
}

/**
 * selection_sort - selection sort.
 * @array: array.
 * @size: size.
 * Return: 0.
 */
void selection_sort(int *array, size_t size)
{
	size_t y, i, min_idx;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (y = 0; y < size - 1; y++)
	{
		min_idx = y;
		for (i = y + 1; i < size; i++)
		{
			if (array[i] < array[min_idx])
			{
				min_idx = i;
			}
		}
		if (y != min_idx)
		{
			swap_elements(array, y, min_idx);
			print_array(array, size);
		}
	}
}
