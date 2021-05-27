/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:25:14 by marvin            #+#    #+#             */
/*   Updated: 2021/05/18 14:56:09 by hiro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_big(const char *big, const char *little)
{
	int	i;

	i = 0;
	while (little[i] && big[i])
	{
		if (little[i] != big[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	if ((int)len < 0)
		return (ft_strstr(big, little));
	i = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[0] && ft_strlen(little) <= (len - i))
		{
			if (check_big(&big[i], little))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
