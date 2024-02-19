#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - get maximum.
 * @array: array.
 * @size: size.
 * Return: 0.
 */
int get_max(int *array, int size)
{
	int max, y;

	for (max = array[0], y = 1; y < size; y++)
	{
		if (array[y] > max)
		{
			max = array[y];
		}
	}
	return (max);
}

/**
 * radix_counting_sort - Sort
 * @array: array.
 * @size: size.
 * @sig: significant.
 * @buff: buffer.
 * Return: 0.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t y;

	for (y = 0; y < size; y++)
	{
		count[(array[y] / sig) % 10] += 1;
	}

	for (y = 1; y < 10; y++)
	{
		count[y] += count[y - 1];
	}

	for (y = size; y > 0; y--)
	{
		buff[count[(array[y - 1] / sig) % 10] - 1] = array[y - 1];
		count[(array[y - 1] / sig) % 10] -= 1;
	}

	for (y = 0; y < size; y++)
	{
		array[y] = buff[y];
	}
}

/**
 * radix_sort - Sort array
 * @array: array.
 * @size: size.
 * Return: 0.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
	{
		return;
	}
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
	{
		return;
	}

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}
	free(buff);
}
