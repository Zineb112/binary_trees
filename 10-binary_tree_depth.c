#include "binary_trees.h"

/**
 * binary_tree_depth - calculat the depth of the  node in a binary tree.
 * @tree: pointer to the node to the depth.
 *
 * Return: If tree is null the function must return 0 or the depth.
 *
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
