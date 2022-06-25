#include "sort.h"

void heapify(int *array, int size, int iterator, int real_size);
void swap(int *a, int *b, int *array, int size);

/**
 * heap_sort - Heap sort algorithm
 * @array: Array to print
 * @size: Array size
 * Return:
 */
void heap_sort(int *array, size_t size)
{
	int iterator;

	for (iterator = (size / 2) - 1; iterator >= 0; iterator--)
	{
		heapify(array, size, iterator, size);
	}

	for (iterator = size - 1; iterator >= 0; iterator--)
	{
		if (iterator != 0)
			swap(&array[0], &array[iterator], array, size);
		heapify(array, iterator, 0, size);
	}
}

/**
 * heapify - Heapify
 * @array: Array to print
 * @size: Array size
 * @iterator: Current array position
 * @real_size: Real array size, not the split one
 * Return:
 */
void heapify(int *array, int size, int iterator, int real_size)
{
	int max = iterator;
	int left_child = (2 * iterator) + 1;
	int rigth_child = (2 * iterator) + 2;

	if (left_child < size && array[left_child] > array[max])
		max = left_child;

	if (rigth_child < size && array[rigth_child] > array[max])
		max = rigth_child;

	if (max != iterator)
	{
		swap(&array[iterator], &array[max], array, real_size);
		heapify(array, size, max, real_size);
	}
}

/**
 * swap - Swaps array values
 * @a: First value
 * @b: Second value
 * @array: Array to print
 * @size: Array size
 * Return:
 */
void swap(int *a, int *b, int *array, int size)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	print_array(array, size);
}
