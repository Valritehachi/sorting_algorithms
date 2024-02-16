#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap.
 * @a: ...
 * @b: ...
 * Return: 0.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - lomuto sort.
 * @array: array.
 * @size: size.
 * @right: right.
 * @left: left.
 * Return: 0.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot = array + right;
	int above, below;

	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - lumuto sort.
 * @array: array.
 * @size: size.
 * @left: left.
 * @right: right.
 * Return: 0.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, p - 1);
		lomuto_sort(array, size, p + 1, right);
	}
}

/**
 * quick_sort - quick sort.
 * @array: array.
 * @size: size.
 * Return: 0.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	lomuto_sort(array, size, 0, size - 1);
}
