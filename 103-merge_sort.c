#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - merge sort.
 * @subarr: subarray.
 * @buff: buffer.
 * @front: ..
 * @mid: ...
 * @back: ....
 * Return: 0.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back)
{
	size_t a, b, i = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (= front, b = mid; a < mid && b < back; i++)
	{
		buff[i] = (subarr[a] < subarr[b]) ? subarr[a++] : subarr[b++];
	}
	for (; a < mid; a++)
	{
		buff[i++] = subarr[a];
	}
	for (; b < back; b++)
	{
		buff[i++] = subarr[b];
	}
	for (a = front, i = 0; a < back; a++)
	{
		subarr[a] = buff[i++];
	}
	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - ...
 * @subarr: ...
 * @buff: ...
 * @front: ...
 * @back: ...
 * Return: 0.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array.
 * @array: ...
 * @size: ...
 * Return: 0.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
	{
		return;
	}

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
	{
		return;
	}

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
