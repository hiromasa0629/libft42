/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:53:00 by hyap              #+#    #+#             */
/*   Updated: 2022/12/05 21:14:59 by hyap             ###   ########.fr       */
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

t_rbtnode	*ft_rbtnew(void *content)
{
	t_rbtnode *new;

	new = (t_rbtnode*)malloc(sizeof(t_rbtnode));
	new->content = content;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

void	ft_rbt_rotate_left(t_rbtnode **root, t_rbtnode **node)
{
	t_rbtnode	*tmp;
	
	tmp = (*node)->right;
	(*node)->right = tmp->left;
	if ((*node)->right != NULL)
		(*node)->right->parent = *node;
	tmp->parent = (*node)->parent;
	if (tmp->parent == NULL) // If (*node) was root and tmp is now root
		*root = tmp;
	
	
	
	
}

int	ft_rbtsearch(t_rbtnode *node, void *content)
{
	if (node == NULL)
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
	if (root == NULL)
		return (NULL);
	if (root->left == NULL)
		return (root->content);
	return (ft_rbt_findmin(root->left));
}

void	*ft_rbt_findmax(t_rbtnode *root)
{
	if (root == NULL)
		return (NULL);
	if (root->right == NULL)
		return (root->content);
	return (ft_rbt_findmax(root->right));
}

int	ft_rbt_findheight(t_rbtnode *root)
{
	int	left;
	int	right;

	if (root == NULL)
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
	if (root->left != NULL)
		ft_rbt_preorder_iter(root->left, f);
	if (root->right != NULL)
		ft_rbt_preorder_iter(root->right, f);
}

void	ft_rbt_inorder_iter(t_rbtnode *root, void (*f)(void *))
{
	if (root->left != NULL)
		ft_rbt_inorder_iter(root->left, f);
	f(root->content);
	if (root->right != NULL)
		ft_rbt_inorder_iter(root->right, f);
}

void	ft_rbt_postorder_iter(t_rbtnode *root, void (*f)(void *))
{
	if (root->left != NULL)
		ft_rbt_postorder_iter(root->left, f);
	if (root->right != NULL)
		ft_rbt_postorder_iter(root->right, f);
	f(root->content);
}

