/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:48:20 by hyap              #+#    #+#             */
/*   Updated: 2022/12/07 20:30:15 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void myprint(void *content)
{
	printf("content: %d, ", *(int *)content);
}

int main(void)
{
	int num[7] = {10, 5, 15, 2, 7, 6, 8};
	// t_rbtnode	*rbt;
	t_rbtnode *rbt;
	t_rbtnode *search;
	int s = 10;

	rbt = NULL;
	g_nil = ft_rbt_createnil();
	rbt = g_nil;
	for (int i = 0; i < 7; i++)
		ft_rbt_insert(&rbt, &(num[i]));
	ft_rbt_inorder_iter(rbt, myprint);
	search = ft_rbt_search(rbt, &s);
	if (search)
		printf("search: %d\n", *((int *)(search->content)));
	printf("\n");
	ft_rbt_delone(&rbt, search, NULL);
	ft_rbt_inorder_iter(rbt, myprint);
	return (0);
}
