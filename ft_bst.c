/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:13:19 by hyap              #+#    #+#             */
/*   Updated: 2022/12/05 15:39:23 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bstnode	*ft_bstnew(int content)
{
	t_bstnode *new;

	new = (t_bstnode*)malloc(sizeof(t_bstnode));
	new->content = content;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

int	ft_bstsearch(t_bstnode *node, int content)
{
	if (node == NULL)
		return (0);
	if (node->content == content)
		return (1);
	if (content <= node->content)
		return (ft_bstsearch(node->left, content));
	else
		return (ft_bstsearch(node->right, content));
}

void	ft_bstinsert(t_bstnode **node, int content)
{
	if (*node == NULL)
		*node = ft_bstnew(content);
	else if (content <= (*node)->content)
	{
		ft_bstinsert(&((*node)->left), content);
	}
	else
		ft_bstinsert(&((*node)->right), content);
}
