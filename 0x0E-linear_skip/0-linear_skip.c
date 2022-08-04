#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: List
 * @value: Value
 * Return: NULL on error
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *list_ct = list, *next_ex = NULL;

	if (!list)
		return (NULL);
	if (list_ct->express && (list_ct->index == list_ct->express->index))
		return (printf("Value checked at index [%u] = [%d]\n",
					   (unsigned int)list_ct->index, list_ct->n),
				(list_ct->n == value) ? list_ct : NULL);
	while (list_ct->express)
	{
		printf("Value checked at index [%u] = [%d]\n",
			   (unsigned int)list_ct->express->index, list_ct->express->n);
		if (value >= list_ct->n && value <= list_ct->express->n)
		{
			printf("Value found between indexes [%u] and [%u]\n",
				   (unsigned int)list_ct->index, (unsigned int)list_ct->express->index);
			break;
		}
		list_ct = list_ct->express;
	}
	if (!list_ct->express)
	{
		next_ex = list_ct;
		while (next_ex->next)
			next_ex = next_ex->next;
		printf("Value found between indexes [%u] and [%u]\n",
			   (unsigned int)list_ct->index, (unsigned int)next_ex->index);
	}
	next_ex = list_ct->express;
	while (list_ct)
	{
		printf("Value checked at index [%u] = [%d]\n",
			   (unsigned int)list_ct->index, list_ct->n);
		if (list_ct == next_ex || list_ct->n == value)
			break;
		list_ct = list_ct->next;
	}
	if (!list_ct || (list_ct == next_ex && list_ct->n != next_ex->n))
		return (NULL);
	return (list_ct);
}
