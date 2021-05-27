/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:19:16 by hyap              #+#    #+#             */
/*   Updated: 2021/05/18 14:50:18 by hiro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*s;
	int			len;
	long long	num;

	num = n;
	len = ft_numlen(n);
	if (n < 0)
		len = len + 1;
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		num = num * -1;
	}
	s[len--] = '\0';
	while (len >= 0)
	{
		s[len--] = (num % 10) + '0';
		if (n < 0 && len < 1)
			break ;
		num = num / 10;
	}
	return (s);
}
