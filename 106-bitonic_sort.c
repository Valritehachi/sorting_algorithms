#include "sort.h"
#include <stdio.h>

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
 * bitonic_merge - bitonic merge.
 * @array: array.
 * @size: size.
 * @start: start.
 * @seq: sequence .
 * @flow: flow.
 * Return: 0
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t y, jump = seq / 2;

	if (seq > 1)
	{
		for (y = start; y < start + jump; y++)
		{
			if ((flow == UP && array[y] > array[y + jump]) ||
			(flow == DOWN && array[y] < array[y + jump]))
			swap_ints(array + y, array + y + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - bitonic sequence.
 * @array: array.
 * @size: size.
 * @start: start.
 * @seq: sequence.
 * @flow: flow.
 * Return: 0.
 */

void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	const char *direction = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, direction);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, direction);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - bitonic Sort.
 * @array: array
 * @size: size.
 * Return: 0.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	bitonic_seq(array, size, 0, size, UP);
}
