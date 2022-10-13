#include "sort.h"

/**
 * top_down_merge_sort - sort 2 subarray
 * @arr: list of numbers
 * @c_arr: copy of the list
 * @start: start index
 * @mid: mid index
 * @end: end index
 */
void top_down_merge_sort(int *arr, int start, int mid, int end, int *c_arr)
{
	int i = 0, j = 0, k = 0;

	i = start, j = mid;
	k = start;
	while (k < end)
	{
		if (i < mid && (j >= end || arr[i] <= arr[j]))
		{
			c_arr[k] = arr[i];
			i++;
		}
		else
		{
			c_arr[k] = arr[j];
			j++;
		}
		k++;
	}
}

/**
 * top_down_merge_split - use divide an conquer to split the array
 * @arr: arr
 * @c_arr: copy array
 * @start: start index
 * @end: end index
 * Return: nothing
 */
void top_down_merge_split(int *c_arr, size_t start, size_t end, int *arr)
{
	size_t mid = 0;

	if (end - start <= 1)
		return;
	mid = (end + start) / 2;

	top_down_merge_split(arr, start, mid, c_arr);
	top_down_merge_split(arr, mid, end, c_arr);
	top_down_merge_sort(c_arr, start, mid, end, arr);
	printf("Merging...\n");
	printf("[left]: ");
	print_array(&(c_arr[start]), mid - start);
	printf("[right]: ");
	print_array(&(c_arr[mid]), end - mid);
	printf("[Done]: ");
	print_array(&(arr[start]), end - start);
}

/**
 * arr_cpy - copy an array
 * @array: list of numbers
 * @new_arr: memory to store the array
 * @size: lenght of the array
 * Return: nothing
 */
void arr_cpy(int *array, int *new_arr, size_t size)
{
	size_t i = 0;

	i = 0;
	while (i < size)
	{
		new_arr[i] = array[i];
		i++;
	}
}

/**
 * merge_sort - Merge sort
 * @array: Array to sort
 * @size: Array size
 * Return:
 */
void merge_sort(int *array, size_t size)
{
	int *c_array = NULL;

	c_array = malloc(sizeof(int) * size);
	if (c_array == NULL)
		return;
	arr_cpy(array, c_array, size);
	top_down_merge_split(c_array, 0, size, array);
	free(c_array);
}
