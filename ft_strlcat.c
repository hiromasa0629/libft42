/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:08:38 by marvin            #+#    #+#             */
/*   Updated: 2021/05/18 14:50:38 by hiro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_len;

	i = 0;
	j = 0;
	d_len = ft_strlen(dest);
	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && d_len < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
		d_len++;
	}
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[j]));
}
