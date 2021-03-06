#include "binary_trees.h"

/**
 * binary_tree_node - insert a new node into the binary tree
 *
 * @parent: the parent node of the node being inserted
 * @value: the value of the node being inserted
 *
 * Return: the new node was inserted
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->left = new_node->right = NULL;
	new_node->parent = parent;
	new_node->n = value;

	/**
     * binary_tree_node:: (*{n}, value) | value < n -> new_node
     */
	if (parent && value < parent->n)
	{
		parent->left = new_node;
	}

	/**
     * binary_tree_node:: (*{n}, value) | value >= n -> new_node
     */
	if (parent && value >= parent->n)
	{
		parent->right = new_node;
	}

	/**
     * binary_tree_node:: (NULL, value) -> new_node
     */
	return (new_node);
}
