/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:53:00 by hyap              #+#    #+#             */
/*   Updated: 2022/12/07 20:36:33 by hyap             ###   ########.fr       */
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

t_rbtnode	*ft_rbt_search(t_rbtnode *node, void *content)
{
	if (node == g_nil)
		return (NULL);
	if (ft_rbt_issame(node->content, content))
		return (node);
	if (ft_rbt_lessthan(content, node->content))
		return (ft_rbt_search(node->left, content));
	else
		return (ft_rbt_search(node->right, content));
}

t_rbtnode	*ft_rbt_findmin(t_rbtnode *root)
{
	if (ft_rbt_isnil(root))
		return (NULL);
	if (ft_rbt_isnil(root->left))
		return (root);
	return (ft_rbt_findmin(root->left));
}

t_rbtnode	*ft_rbt_findmax(t_rbtnode *root)
{
	if (ft_rbt_isnil(root))
		return (NULL);
	if (ft_rbt_isnil(root->right))
		return (root);
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

static t_rbtnode	*ft_rbt_preinsert(t_rbtnode **node, void *content, t_rbtnode *parent)
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

static void	ft_rbt_insertfixup(t_rbtnode **root, t_rbtnode *node)
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
	ft_rbt_insertfixup(node, inserted);
}

static void	ft_rbt_transplant(t_rbtnode **root, t_rbtnode *u, t_rbtnode *v)
{
	if (u->parent == g_nil)
		*root = v;
	else if (u->parent->left == u)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v != g_nil)
		v->parent = u->parent;
}

static void	ft_rbt_delfixup(t_rbtnode **root, t_rbtnode *node)
{
	t_rbtnode	*w;
	
	while (node != *root && node->color == BLACK)
	{
		// if (node == g_nil)
		// 	printf("is g_nil\n");
		if (node == node->parent->left)
		{
			w = node->parent->right;
			if (w->color == RED)
			{
				w->color = BLACK;
				node->parent->color = RED;
				ft_rbt_rotate_left(root, node->parent);
				w = node->parent->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK)
			{
				w->color = RED;
				node = node->parent;
			}
			else
			{
				if (w->right->color == BLACK)
				{
					w->left->color = BLACK;
					w->color = RED;
					ft_rbt_rotate_right(root, w);
					w = node->parent->right;
				}
				w->color = node->parent->color;
				node->parent->color = BLACK;
				w->right->color = BLACK;
				ft_rbt_rotate_left(root, node->parent);
				node = *root;
			}
		}
		else if (node == node->parent->right)
		{
			w = node->parent->left;
			if (w->color == RED)
			{
				w->color = BLACK;
				node->parent->color = RED;
				ft_rbt_rotate_right(root, node->parent);
				w = node->parent->left;
			}
			if (w->left->color == BLACK && w->right->color == BLACK)
			{
				w->color = RED;
				node = node->parent;
			}
			else
			{
				if (w->left->color == BLACK)
				{
					w->right->color = BLACK;
					w->color = RED;
					ft_rbt_rotate_left(root, w);
					w = node->parent->left;
				}
				w->color = node->parent->color;
				node->parent->color = BLACK;
				w->left->color = BLACK;
				ft_rbt_rotate_right(root, node->parent);
				node = *root;
			}
		}
	}
	node->color = BLACK;
}

void	ft_rbt_delone(t_rbtnode **root, t_rbtnode *tbd, void (*del)(void *))
{
	enum color	ori;
	t_rbtnode	*x;
	t_rbtnode	*small;

	if (!tbd)
		return ;
	ori = tbd->color;
	
	if (tbd->left == g_nil)
	{
		x = tbd->right;
		ft_rbt_transplant(root, tbd, tbd->right);
	}
	else if (tbd->right == g_nil)
	{
		x = tbd->left;
		ft_rbt_transplant(root, tbd, tbd->left);
	}
	else
	{
		small = ft_rbt_findmin(tbd->right);
		ori = small->color;
		x = small->right;
		if (small->parent != tbd)
		{
			ft_rbt_transplant(root, small, small->right);
			small->right = tbd->right;
			small->right->parent = small;
		}
		else
			x->parent = small;
		ft_rbt_transplant(root, tbd, small);
		small->left = tbd->left;
		small->left->parent = small;
		small->color = tbd->color;
	}
	printf("x: %d\n", *(int *)tbd->content);
	if (ori == BLACK)
		ft_rbt_delfixup(root, x);
	if (del)
		del(tbd->content);
	free(tbd);
}
