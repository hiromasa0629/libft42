/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:13:19 by hyap              #+#    #+#             */
/*   Updated: 2022/12/07 15:39:24 by hyap             ###   ########.fr       */
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

t_bstnode	*ft_bstnew(void *content, t_bstnode *parent)
{
	t_bstnode *new;

	new = (t_bstnode*)malloc(sizeof(t_bstnode));
	new->content = content;
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	return (new);
}

t_bstnode	*ft_bst_search(t_bstnode *node, void *content)
{
	if (node == NULL)
		return (NULL);
	if (ft_bst_issame(node->content, content))
		return (node);
	if (ft_bst_lessthan(content, node->content))
		return (ft_bst_search(node->left, content));
	else
		return (ft_bst_search(node->right, content));
}

void	ft_bst_insert(t_bstnode **node, void *content, t_bstnode *parent)
{
	if (*node == NULL)
		*node = ft_bstnew(content, parent);
	else if (ft_bst_lessthan(content, (*node)->content))
		ft_bst_insert(&((*node)->left), content, *node);
	else
		ft_bst_insert(&((*node)->right), content, *node);
}

t_bstnode	*ft_bst_findmin(t_bstnode *root)
{
	if (root == NULL)
		return (NULL);
	if (root->left == NULL)
		return (root);
	return (ft_bst_findmin(root->left));
}

t_bstnode	*ft_bst_findmax(t_bstnode *root)
{
	if (root == NULL)
		return (NULL);
	if (root->right == NULL)
		return (root);
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
	if (root->parent)
		printf(", parent: %d\n", *(int *)(root->parent->content));
	printf("\n");
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

static void	ft_bst_transplant(t_bstnode **root, t_bstnode *u, t_bstnode *v)
{
	if (u->parent == NULL)
		*root = v;
	else if (u->parent->left == u)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v != NULL)
		v->parent = u->parent;
}

void	ft_bst_delone(t_bstnode **root, t_bstnode *tbd, void (*del)(void *))
{
	t_bstnode	*small;

	if (!tbd)
		return ;
	if (tbd->left == NULL)
		ft_bst_transplant(root, tbd, tbd->right);
	else if (tbd->right == NULL)
		ft_bst_transplant(root, tbd, tbd->left);
	else
	{
		small = ft_bst_findmin(tbd->right);
		if (small->parent != tbd)
		{
			ft_bst_transplant(root, small, small->right);
			small->right = tbd->right;
			small->right->parent = small;
		}
		ft_bst_transplant(root, tbd, small);
		small->left = tbd->left;
		small->left->parent = small;
	}
	if (del)
		del(tbd->content);
	free(tbd);
}


