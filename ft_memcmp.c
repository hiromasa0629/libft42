/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:47:41 by marvin            #+#    #+#             */
/*   Updated: 2021/05/18 12:05:59 by hiro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*one;
	unsigned char	*two;
	size_t			i;

	i = 0;
	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	while (i < n)
	{
		if (one[i] != two[i])
			return (one[i] - two[i]);
		i++;
	}
	return (0);
}
