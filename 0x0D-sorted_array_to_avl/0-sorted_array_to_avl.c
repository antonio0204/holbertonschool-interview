#include "binary_trees.h"

/**
 * create_alv_node - create a node for a binary tree
 * @n: value to insert in the node
 * Return: a node on succes
 */
avl_t *create_alv_node(int n)
{
	avl_t *new_node = NULL;

	new_node = malloc(sizeof(avl_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * create_binary_tree - Create AVL
 * @array: list of number to convert to b_tree
 * @frs: index of the frs num in the list
 * @last: index of the last num in the list
 * @parent: pointer with the parent address
 * @or: n--neutro, l--left, r--right position
 * Return: a pointer head of the tree in succes, NULL otherwise
 */
avl_t *create_binary_tree(int *array, size_t frs, size_t last,
	avl_t *parent, char or)
{
	avl_t *new_node = NULL, *last_node = NULL;

	if (last - frs > 1)
	{
		new_node = create_alv_node(array[(int)((last + frs) / 2) - 1]);
		new_node->parent = parent;
		if (or == 'l')
			parent->left = new_node;
		else if (or == 'r')
			parent->right = new_node;
		create_binary_tree(array, frs, (int)((last + frs) / 2) - 1, new_node, 'l');
		create_binary_tree(array, (int)((last + frs) / 2) + 1, last, new_node, 'r');
	}
	else if (last - frs == 1)
	{
		new_node = create_alv_node(array[last - 1]);
		last_node = create_alv_node(array[frs - 1]);
		if (or == 'l')
		{
			parent->left = last_node, last_node->parent = parent;
			new_node->parent = last_node, last_node->right = new_node;
		}
		else if (or == 'r')
		{
			parent->right = last_node, last_node->parent = parent;
			new_node->parent = last_node, last_node->right = new_node;
		}
	}
	else
	{
		new_node = create_alv_node(array[last - 1]);
		new_node->parent = parent;
		if (or == 'l')
			parent->left = new_node;
		else if (or == 'r')
			parent->right = new_node;
	}
	return (new_node);
}

/**
 * sorted_array_to_avl - convert a sorted array to an avl b_tree
 * @array: Array numbers
 * @size: Size @array
 * Return: a pointer head of the tree in succes
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new_node = NULL, *last_node = NULL;

	if (!array || size == 0)
		return (NULL);
	if (size == 1)
	{
		new_node = create_alv_node(array[0]);
		return (new_node);
	}
	if (size == 2)
	{
		new_node = create_alv_node(array[1]);
		last_node = create_alv_node(array[0]);
		last_node->right = new_node, new_node->parent = last_node;
		return (last_node);
	}
	return (create_binary_tree(array, 1, size, NULL, 'n'));
}
