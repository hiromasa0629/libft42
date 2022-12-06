/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:53:00 by hyap              #+#    #+#             */
/*   Updated: 2022/12/06 20:56:22 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_rbt_issame(void *lhs, void *rhs)
{
	int a;
	int	b;

	a = *((int*)lhs);
	b = *((int*)rhs);
	if (a == b)
		return (1);
	return (0);
}

static int ft_rbt_lessthan(void *lhs, void *rhs)
{
	int a;
	int	b;

	a = *((int*)lhs);
	b = *((int*)rhs);
	if (a <= b)
		return (1);
	return (0);
}

static int	ft_rbt_isnil(t_rbtnode *a)
{
	return (a == g_nil || a == NULL);
}

t_rbtnode	*ft_rbt_createnil(void)
{
	t_rbtnode	*nil;

	nil = (t_rbtnode *)malloc(sizeof(t_rbtnode));
	nil->color = BLACK;
	nil->content = NULL;
	nil->left = NULL;
	nil->right = NULL;
	nil->parent = NULL;
	return (nil);
}

t_rbtnode	*ft_rbtnew(void *content, t_rbtnode *parent)
{
	t_rbtnode *new;

	new = (t_rbtnode*)malloc(sizeof(t_rbtnode));
	new->content = content;
	new->left = g_nil;
	new->right = g_nil;
	new->parent = parent;
	new->color = RED;
	return (new);
}

void	ft_rbt_rotate_left(t_rbtnode **root, t_rbtnode *node)
{
	t_rbtnode	*tmp;

	tmp = node->right;
	node->right = tmp->left;
	if (!ft_rbt_isnil(tmp->left))
		tmp->left->parent = node;
	tmp->parent = node->parent;
	if (ft_rbt_isnil(node->parent)) // If (*node) was root and tmp is now root
		*root = tmp;
	else if (node->parent->left == node) // If (*node) was a left child
		node->parent->left  = tmp;
	else if (node->parent->right == node) // If (*node) was a right child
		node->parent->right = tmp;
	tmp->left = node;
	node->parent = tmp;
}

void	ft_rbt_rotate_right(t_rbtnode **root, t_rbtnode *node)
{
	t_rbtnode *tmp;

	tmp = node->left;
	node->left = tmp->right;
	if (!ft_rbt_isnil(tmp->left))
		tmp->right->parent = node;
	tmp->parent = node->parent;
	if (ft_rbt_isnil(node->parent))
		*root = tmp;
	else if (node->parent->left == node)
		node->parent->left = tmp;
	else if (node->parent->right == node)
		node->parent->right = tmp;
	tmp->right = node;
	node->parent = tmp;
}

int	ft_rbtsearch(t_rbtnode *node, void *content)
{
	if (node == g_nil)
		return (0);
	if (ft_rbt_issame(node->content, content))
		return (1);
	if (ft_rbt_lessthan(node->content, content))
		return (ft_rbtsearch(node->left, content));
	else
		return (ft_rbtsearch(node->right, content));
}

void	*ft_rbt_findmin(t_rbtnode *root)
{
	if (ft_rbt_isnil(root))
		return (NULL);
	if (ft_rbt_isnil(root->left))
		return (root->content);
	return (ft_rbt_findmin(root->left));
}

void	*ft_rbt_findmax(t_rbtnode *root)
{
	if (ft_rbt_isnil(root))
		return (NULL);
	if (ft_rbt_isnil(root->right))
		return (root->content);
	return (ft_rbt_findmax(root->right));
}

int	ft_rbt_findheight(t_rbtnode *root)
{
	int	left;
	int	right;

	if (ft_rbt_isnil(root))
		return (-1);
	left = ft_rbt_findheight(root->left);
	right = ft_rbt_findheight(root->right);
	if (left >= right)
		return (left + 1);
	return (right + 1);
}

void	ft_rbt_preorder_iter(t_rbtnode *root, void (*f)(void *))
{
	f(root->content);
	if (!ft_rbt_isnil(root->left))
		ft_rbt_preorder_iter(root->left, f);
	if (!ft_rbt_isnil(root->right))
		ft_rbt_preorder_iter(root->right, f);
}

void	ft_rbt_inorder_iter(t_rbtnode *root, void (*f)(void *))
{
	if (!ft_rbt_isnil(root->left))
		ft_rbt_inorder_iter(root->left, f);
	f(root->content);
	printf("color: %s\n", (root->color == RED ? "RED" : "BLACK"));
	if (!ft_rbt_isnil(root->parent))
		printf(" parent: %d\n", *((int *)root->parent->content));
	printf("\n");
	if (!ft_rbt_isnil(root->right))
		ft_rbt_inorder_iter(root->right, f);
}

void	ft_rbt_postorder_iter(t_rbtnode *root, void (*f)(void *))
{
	if (!ft_rbt_isnil(root->left))
		ft_rbt_postorder_iter(root->left, f);
	if (!ft_rbt_isnil(root->right))
		ft_rbt_postorder_iter(root->right, f);
	f(root->content);
}

t_rbtnode	*ft_rbt_preinsert(t_rbtnode **node, void *content, t_rbtnode *parent)
{
	if (ft_rbt_isnil(*node))
	{
		*node = ft_rbtnew(content, parent);
		return (*node);
	}
	else if (ft_rbt_lessthan(content, (*node)->content))
		return (ft_rbt_preinsert(&((*node)->left), content, *node));
	else
		return (ft_rbt_preinsert(&((*node)->right), content, *node));
}

void	ft_rbt_fixup(t_rbtnode **root, t_rbtnode *node)
{
	t_rbtnode	*uncle;
	
	while (node->parent->color == RED)
	{
		if (node->parent == node->parent->parent->left) // node parent is a left child
		{
			uncle = node->parent->parent->right;
			if (uncle->color == RED)
			{
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				uncle->color = BLACK;
				node = node->parent->parent;
			}
			else if (uncle->color == BLACK)
			{
				if (node == node->parent->right) // node is a right child
				{
					node = node->parent;
					ft_rbt_rotate_left(root, node);
				}
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				ft_rbt_rotate_right(root, node->parent->parent);
			}
		}
		else if (node->parent == node->parent->parent->right) // node parent is a right child
		{
			uncle = node->parent->parent->left;
			if (uncle->color == RED)
			{
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				uncle->color = BLACK;
				node = node->parent->parent;
			}
			else if (uncle->color == BLACK)
			{
				if (node == node->parent->left) // node is a left child
				{
					node = node->parent;
					ft_rbt_rotate_right(root, node);
				}
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				ft_rbt_rotate_left(root, node->parent->parent);
			}
		}
	}
	(*root)->color = BLACK;
}

void	ft_rbt_insert(t_rbtnode **node, void *content)
{
	t_rbtnode	*inserted;
	
	inserted = ft_rbt_preinsert(node, content, g_nil);
	ft_rbt_fixup(node, inserted);
}
