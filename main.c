/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:48:20 by hyap              #+#    #+#             */
/*   Updated: 2022/12/06 16:38:24 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	myprint(void *content)
{
	printf("content: %d\n", *(int *)content);
}

int	main(void)
{
	int num[7] = {10, 5, 15, 2, 7, 6, 8};
	t_rbtnode	*rbt;

	g_nil = ft_rbt_createnil();
	rbt = g_nil;
	for (int i = 0; i < 7; i++)
		ft_rbtinsert(&rbt, &(num[i]), NULL);
	ft_rbt_rotate_left(&rbt, rbt->left);
	ft_rbt_inorder_iter(rbt, myprint);
	printf("\n === \n");
	ft_rbt_rotate_right(&rbt, rbt->left);
	ft_rbt_inorder_iter(rbt, myprint);
	return (0);
}
