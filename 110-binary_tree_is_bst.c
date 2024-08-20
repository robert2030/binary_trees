#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_util - function to check if the tree is valid BST
 * @node: Current node
 * @min: Minimum value for nodes
 * @max: Maximum value ofr nodes
 * Return: 1 if the tree BST 0 otherwise
 */

int is_bst_util(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);

	if (node->n <= min || node->n >= max)
		return (0);

	return (is_bst_util(node->left, min, node->n) && is_bst_util(
				node->right, node->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: A pointer to the root node
 * Return: 1 if tree is BST 0 if not
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_util(tree, INT_MIN, INT_MAX));
}
