#include "sort.h"

/**
 * swap_ints - Swap.
 * @a: a.
 * @b: b.
 * Return: 0.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - shell Sort
 * @array: array.
 * @size: size.
 * Return: 0.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, a, b;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (gap = size / 3; gap > 0; gap /= 3)
	{
		for (a = gap; a < size; a++)
		{
			for (b = a; b >= gap && array[b - gap] > array[b]; b -= gap)
			{
				swap_ints(array + b, array + (b - gap));
			}
		}
		print_array(array, size);
	}
}
