/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:48:20 by hyap              #+#    #+#             */
/*   Updated: 2022/12/07 15:37:45 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	myprint(void *content)
{
	printf("content: %d, ", *(int *)content);
}

int	main(void)
{
	int num[7] = {10, 5, 15, 2, 7, 6, 8};
	// t_rbtnode	*rbt;
	t_bstnode	*bst;
	t_bstnode	*search;
	int	s = 7;

	bst = NULL;
	// g_nil = ft_rbt_createnil();
	// rbt = g_nil;
	for (int i = 0; i < 7; i++)
		ft_bst_insert(&bst, &(num[i]), NULL);
	ft_bst_inorder_iter(bst, myprint);
	search = ft_bst_search(bst, &s);
	if (search)
		printf("search: %d\n", *((int *)(search->content)));
	printf("\n");
	ft_bst_delone(&bst, search, NULL);
	ft_bst_inorder_iter(bst, myprint);
	return (0);
}
