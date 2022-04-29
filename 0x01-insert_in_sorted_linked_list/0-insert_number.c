#include "lists.h"

/**
 * insert_node - Inserts a node in an ordered linked list
 * @head: Head of the list
 * @number: Number to insert in the linked list
 * Return: New node created or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *node_change, *iterator = *head;

	new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);
	new_node->n = number;
	new_node->next = NULL;

	if (!head || !(*head))
	{
		(*head) = new_node;
		return (new_node);
	}
	if (number < (*head)->n)
	{
		new_node->next = (*head);
		(*head) = new_node;
		return (new_node);
	}

	node_change = iterator;
	while (iterator->next)
	{
		if (number < iterator->n && number >= node_change->n)
		{
			new_node->next = iterator;
			node_change->next = new_node;
			return (new_node);
		}
		node_change = iterator;
		iterator = iterator->next;
	}
	iterator->next = new_node;
	return (new_node);
}
