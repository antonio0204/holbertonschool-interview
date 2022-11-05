#include "list.h"

/**
 * create_node - allocate memory to store the new node
 * @str: the strign to copy into the new node
 * Return: a new List node, NULL otherwise
 */
List *create_node(char *str)
{
	List *new_node = NULL;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	new_node->prev = NULL;
	new_node->next = NULL;

	if (str && !new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	return (new_node);
}


/**
 * add_node_end - Add a new node to the end of a
 * double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node = NULL, *tail = NULL, *head = NULL;

	if (!list)
		return (NULL);

	new_node = create_node(str);
	if (!new_node)
		return (NULL);

	head = *list;
	if (!head)
	{
		new_node->next = new_node;
		new_node->prev = new_node;

		*list = new_node;
	}
	else
	{
		tail = head->prev;

		new_node->next = head;
		tail->next = new_node;
		new_node->prev = tail;
		head->prev = new_node;
	}

	return (new_node);
}

/**
 * add_node_begin - Add a new node to the beginning of a
 * double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node = NULL;

	new_node = add_node_end(list, str);
	if (!new_node)
		return (NULL);

	*list = new_node;
	return (new_node);
}
