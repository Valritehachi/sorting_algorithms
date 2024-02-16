#include "sort.h"
#include <stddef.h>
/**
 * swap_ints - Swap integers.
 * @a: ...
 * @b: ...
 * Return: 0
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an array.
 * @array: array.
 * @size: size.
 * Return: 0
 */
void bubble_sort(int *array, size_t size)
{
	size_t y, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (y = 0; y < len - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				swap_ints(array + y, array + y + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
