#include "search_algos.h"

void print_array(int *array, int start, int end);
int binary_search(int *array, int first, int last, int value);

/**
 * advanced_binary - Binary search
 * @array: Array to make search
 * @size: Size of @array
 * @value: Value toi find
 * Return: Position of @value on @array on success, -1 otherwise
 */
int advanced_binary(int *array, size_t size, int value)
{
	int first = 0, last = size - 1;

	if (!array || size == 0)
		return (-1);
	return (binary_search(array, first, last, value));
}

/**
 * binary_search - Binary search
 * @array: Array to make search
 * @first: First position of @array
 * @last: Last position of @array
 * @value: Value toi find
 * Return: Position of @value on @array on success, -1 otherwise
 */
int binary_search(int *array, int first, int last, int value)
{
	int middle = (first + last) / 2;

	if (first > last)
		return (-1);

	print_array(array, first, last);

	if (array[middle] < value)
		return (binary_search(array, middle + 1, last, value));
	else if (array[middle] >= value)
		last = middle;

	if (array[first] == value && first == middle)
		return (first);

	return (binary_search(array, first, last, value));
}

/**
 * print_array - Print array
 * @array: Array to make search
 * @start: Position to start printing
 * @end: Position to end printing
 * Return:
 */
void print_array(int *array, int start, int end)
{
	int iterator;

	printf("Searching in array: ");
	for (iterator = start; iterator <= end; iterator++)
	{
		if (iterator != start)
			printf(", ");
		printf("%d", array[iterator]);
	}
	putchar('\n');
}
