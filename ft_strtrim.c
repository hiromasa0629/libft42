/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:03:23 by hyap              #+#    #+#             */
/*   Updated: 2021/05/18 14:54:07 by hiro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_front(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i++;
	}
	return (i);
}

int	check_back(const char *s1, const char *set, int len1)
{
	int	i;

	i = ft_strlen(s1);
	while (i > len1)
	{
		if (!ft_strchr(set, s1[i - 1]))
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		len1;
	int		len2;
	int		len;
	char	*trim;
	int		i;

	if (!s1 || !set)
		return (ft_strdup(s1));
	len1 = check_front(s1, set);
	len2 = check_back(s1, set, len1);
	len = len2 - len1;
	trim = (char *)malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (NULL);
	i = 0;
	if (len != 0)
	{
		while (len1 < len2)
			trim[i++] = s1[len1++];
	}
	trim[i] = '\0';
	return (trim);
}
