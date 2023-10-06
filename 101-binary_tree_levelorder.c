#include "binary_trees.h"

/**
 * struct node_s - singly linked list
 * @node: Pointer to a binary tree node
 * @next: Pointer to the next node in the list
 */

typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} ll;

ll *append(ll *head, const binary_tree_t *btnode);
void free_list(ll *head);
ll *get_children(ll *head, const binary_tree_t *parent);
void levels_rec(ll *head, void (*func)(int));

/**
 * binary_tree_levelorder - Performs level-order traversal of a binary tree.
 * @tree: A Pointer to the  root node of the tree to traverse.
 * @func: A Pointer to a  function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	ll *children = NULL;

	func(tree->n);
	children = get_children(children, tree);
	levels_rec(children, func);

	free_list(children);
}

/**
 * levels_rec - Calls the specified  function on all nodes at each level.
 * @head: A Pointer to the head of a  linked list with nodes at one level.
 * @func: A Pointer to a function to  call for each node.
 */

void levels_rec(ll *head, void (*func)(int))
{
	ll *children = NULL, *curr = NULL;

	if (!head)
		return;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		func(curr->node->n);
		children = get_children(children, curr->node);
	}
	levels_rec(children, func);
	free_list(children);
}

/**
 * get_children - appends children  of parent to linked list.
 * @head: A Pointer to head of linked  list where children will be appended.
 * @parent: A Pointer to  node whose  children we want to append.
 * Return: A Pointer to head of linked  list of children.
 */
ll *get_children(ll *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = append(head, parent->left);
	if (parent->right)
		head = append(head, parent->right);
	return (head);
}

/**
 * append - adds a new node at the end of a linkedlist
 * @head: pointer to head of linked list
 * @btnode: A const binary tree node to append
 * Return: A pointer to head, or NULL on failure
 */
ll *append(ll *head, const binary_tree_t *btnode)
{
	ll *new = NULL, *last = NULL;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->node = btnode;
		new->next = NULL;
		if (!head)
			head = new;
		else
		{
			last = head;
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
	return (head);
}

/**
 * free_list - free the nodes in a linked list
 * @head: A pointer to the head of list_t linked list
 */
void free_list(ll *head)
{
	ll *ptr = NULL;

	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
