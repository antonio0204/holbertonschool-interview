#include "binary_trees.h"

/**
 * heapify - fix the heap_max
 * @root: double pointer to the root node of the heap
 * Return: Nothing
 */
void heapify(binary_tree_t *root)
{
	binary_tree_t *child = NULL;
	int tem_num = 0;

	while (1)
	{
		if (!root->left)
			break;
		else if (!root->right)
			child = root->left;
		else
		{
			if (root->left->n >= root->right->n)
				child = root->left;
			else
				child = root->right;
		}

		if (root->n >= child->n)
			break;

		tem_num = root->n;
		root->n = child->n;
		child->n = tem_num;

		root = child;
	}
}

/**
 * get_num_nodes - get the number of nodes of heap tree
 * @root: double pointer to the root node of the heap
 * Return: all the nodes in heap tree
 */
int get_num_nodes(heap_t *root)
{
	int l = 0, r = 0;

	if (!root)
		return (0);

	l = get_num_nodes(root->left);
	r = get_num_nodes(root->right);

	return (1 + l + r);
}

/**
 * get_node_end - get the last node in heap_min
 * @root: double pointer to the root node of the heap
 * Return: pointer to the last node of the heap
 */
binary_tree_t *get_node_end(heap_t *root)
{
	int nodes = 0, size_heap = 0;
	binary_tree_t *node_end = NULL;

	size_heap = get_num_nodes(root);

	for (nodes = 1; nodes <= size_heap; nodes <<= 1)
		;
	nodes >>= 2;

	for (node_end = root; nodes > 0; nodes >>= 1)
	{
		if (size_heap & nodes)
			node_end = node_end->right;
		else
			node_end = node_end->left;
	}

	return (node_end);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: the value stored in the root node
 */
int heap_extract(heap_t **root)
{
	binary_tree_t *node_end = NULL, *head_node = NULL;
	int extracted_num = 0;

	if (!root || !*root)
		return (0);

	head_node = *root;
	if (!head_node->left && !head_node->right)
	{
		extracted_num = head_node->n;
		free(head_node);
		*root = NULL;
		return (extracted_num);
	}

	head_node = *root;
	extracted_num = head_node->n;

	node_end = get_node_end(*root);

	if (node_end->parent->left == node_end)
		node_end->parent->left = NULL;
	else
		node_end->parent->right = NULL;

	node_end->left = head_node->left;
	node_end->right = head_node->right;
	node_end->parent = head_node->parent;

	if (head_node->left)
		head_node->left->parent = node_end;
	if (head_node->right)
		head_node->right->parent = node_end;

	*root = node_end;
	free(head_node);

	heapify(*root);

	return (extracted_num);
}
