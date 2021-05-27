/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:44:47 by hyap              #+#    #+#             */
/*   Updated: 2021/05/18 12:04:41 by hiro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*s;

	s = (void *)malloc(n * size);
	if (!s)
		return (NULL);
	ft_bzero(s, n * size);
	return (s);
}
