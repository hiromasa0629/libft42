/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:16:17 by marvin            #+#    #+#             */
/*   Updated: 2021/05/18 14:54:31 by hiro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	i = -1;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (++i < n)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			return (dest + i + 1);
	}
	return (NULL);
}
