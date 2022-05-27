#include "lists.h"

/**
 * is_palindrome - Finds if a linked list is a palindrome
 * @head: Head of the Linked list
 * Return: 0 if it is nota palidrome, 1 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *iterator = *head;
	int head_size = 0, list[4000], i_aux;

	if (!iterator)
		return (1);

	while (iterator)
	{
		list[head_size] = iterator->n;
		head_size++;
		iterator = iterator->next;
	}
	for (i_aux = 0; i_aux < head_size; i_aux++)
	{
		if (i_aux > head_size / 2 || list[i_aux] != list[head_size - 1 - i_aux])
			break;
	}

	if (i_aux <= head_size / 2)
		return (0);
	return (1);
}


