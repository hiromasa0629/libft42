/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:13:19 by hyap              #+#    #+#             */
/*   Updated: 2022/12/05 19:26:06 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_bst_issame(void *lhs, void *rhs)
{
	int a;
	int	b;
	
	a = *((int*)lhs);
	b = *((int*)rhs);
	if (a == b)
		return (1);
	return (0);
}

static int ft_bst_lessthan(void *lhs, void *rhs)
{
	int a;
	int	b;
	
	a = *((int*)lhs);
	b = *((int*)rhs);
	if (a <= b)
		return (1);
	return (0);
}

t_bstnode	*ft_bstnew(void *content)
{
	t_bstnode *new;

	new = (t_bstnode*)malloc(sizeof(t_bstnode));
	new->content = content;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

int	ft_bstsearch(t_bstnode *node, void *content)
{
	if (node == NULL)
		return (0);
	if (ft_bst_issame(node->content, content))
		return (1);
	if (ft_bst_lessthan(node->content, content))
		return (ft_bstsearch(node->left, content));
	else
		return (ft_bstsearch(node->right, content));
}

void	ft_bstinsert(t_bstnode **node, void *content)
{
	if (*node == NULL)
		*node = ft_bstnew(content);
	else if (ft_bst_lessthan(content, (*node)->content))
		ft_bstinsert(&((*node)->left), content);
	else
		ft_bstinsert(&((*node)->right), content);
}

void	*ft_bst_findmin(t_bstnode *root)
{
	if (root == NULL)
		return (NULL);
	if (root->left == NULL)
		return (root->content);
	return (ft_bst_findmin(root->left));
}

void	*ft_bst_findmax(t_bstnode *root)
{
	if (root == NULL)
		return (NULL);
	if (root->right == NULL)
		return (root->content);
	return (ft_bst_findmax(root->right));
}

int	ft_bst_findheight(t_bstnode *root)
{
	int	left;
	int	right;

	if (root == NULL)
		return (-1);
	left = ft_bst_findheight(root->left);
	right = ft_bst_findheight(root->right);
	if (left >= right)
		return (left + 1);
	return (right + 1);
}

void	ft_bst_preorder_iter(t_bstnode *root, void (*f)(void *))
{
	f(root->content);
	if (root->left != NULL)
		ft_bst_preorder_iter(root->left, f);
	if (root->right != NULL)
		ft_bst_preorder_iter(root->right, f);
}

void	ft_bst_inorder_iter(t_bstnode *root, void (*f)(void *))
{
	if (root->left != NULL)
		ft_bst_inorder_iter(root->left, f);
	f(root->content);
	if (root->right != NULL)
		ft_bst_inorder_iter(root->right, f);
}

void	ft_bst_postorder_iter(t_bstnode *root, void (*f)(void *))
{
	if (root->left != NULL)
		ft_bst_postorder_iter(root->left, f);
	if (root->right != NULL)
		ft_bst_postorder_iter(root->right, f);
	f(root->content);
}
