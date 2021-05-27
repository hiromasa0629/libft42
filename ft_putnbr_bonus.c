/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:55:50 by hyap              #+#    #+#             */
/*   Updated: 2021/05/18 12:11:25 by hiro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long long	num;
	char		cnum;

	num = n;
	if (n < 0)
	{
		ft_putchar('-');
		num = num * -1;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	cnum = (num % 10) + '0';
	ft_putchar(cnum);
}
