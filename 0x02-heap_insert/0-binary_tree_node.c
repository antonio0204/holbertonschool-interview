#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node
 * @parent: parent of tree
 * @value: value of new node
 * Return: new node or NULL if failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

