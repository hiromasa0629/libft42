/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiro <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:01:49 by hiro              #+#    #+#             */
/*   Updated: 2021/05/18 12:11:38 by hiro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		if (to_find[0] == str[i])
		{
			j = 0;
			while (str[i + j] == to_find[j])
			{
				j++;
				if (to_find[j] == '\0')
					return ((char *)&str[i]);
			}
		}
		i++;
	}
	return (0);
}
