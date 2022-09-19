#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node;
	heap_t *temp;

	if (root == NULL || *root == NULL)
		return (0);
	value = (*root)->n;
	last_node = get_last_node(*root);
	if (last_node == *root)
	{
		free(*root);
		*root = NULL;
		return (value);
	}
	(*root)->n = last_node->n;
	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;
	free(last_node);
	temp = *root;
	heapify(temp);
	return (value);
}

/**
 * heapify - heapify the tree
 * @node: pointer to the root node of the heap
 * Return: void
 */
heap_t *get_last_node(heap_t *node)
{
	heap_t *last_node;
	// base case for recursion
	if (node == NULL)
		return (NULL);

	// if node is a leaf node
	if (node->left == NULL && node->right == NULL)
		return (node);

	if (node->right == NULL)
		return (get_last_node(node->left));

	last_node = get_last_node(node->right);

	if (last_node != node->right)
		return (last_node);

	return (get_last_node(node->left));
}

/**
 * heapify - heapify the tree
 * @node: pointer to the root node of the heap
 * Return: void
 */
void heapify(heap_t *node)
{
	int value;
	heap_t *temp;

	temp = node;
	if (temp->left == NULL && temp->right == NULL)
		return;
	if (temp->right == NULL && temp->n < temp->left->n)
	{
		value = temp->n;
		temp->n = temp->left->n;
		temp->left->n = value;
		heapify(temp->left);
	}
	if (temp->right == NULL)
		return;
	if (temp->left->n > temp->right->n && temp->n < temp->left->n)
	{
		value = temp->n;
		temp->n = temp->left->n;
		temp->left->n = value;
		heapify(temp->left);
		return;
	}
	if (temp->n < temp->right->n)
	{
		value = temp->n;
		temp->n = temp->right->n;
		temp->right->n = value;
		heapify(temp->right);
	}
}