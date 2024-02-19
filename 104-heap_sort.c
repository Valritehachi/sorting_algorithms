#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t heap_size, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap integers.
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
 * max_heapify - ...
 * @array: array.
 * @size: size.
 * @heap_size: size of heap.
 * @root: root.
 * Return: 0.
 */
void max_heapify(int *array, size_t size, size_t heap_size, size_t root)
{
	size_t left, right, largest;

	left = 2 * root + 1;
	right = 2 * root + 2;
	largest = root;

	if (left < heap_size && array[left] > array[largest])
	{
		largest = left;
	}
	if (right < heap_size && array[right] > array[largest])
	{
		largest = right;
	}
	if (largest != root)
	{
		swap_ints(array + root, array + largest);
		print_array(array, size);
		max_heapify(array, size, heap_size, largest);
	}
}

/**
 * heap_sort - Sort an array.
 * @array: An array.
 * @size: size.
 * Return: 0.
 */
void heap_sort(int *array, size_t size)
{
	int y;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (y = size / 2 - 1; y >= 0; y--)
	{
		max_heapify(array, size, size, y);
	}
	for (y = size - 1; y > 0; y--)
	{
		swap_ints(array, array + y);
		print_array(array, size);
		max_heapify(array, size, y, 0);
	}
}
