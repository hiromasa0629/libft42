/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:56:42 by hyap              #+#    #+#             */
/*   Updated: 2021/05/18 12:04:12 by hiro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	ans;
	int	res;

	ans = 1;
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			ans = ans * -1;
		i++;
	}
	res = 0;
	while (ft_isdigit(s[i]))
		res = (res * 10) + (s[i++] - '0');
	ans = ans * res;
	return (ans);
}
