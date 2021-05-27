/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:37:51 by hyap              #+#    #+#             */
/*   Updated: 2021/05/27 13:05:20 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	string_count(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] != c)
		{
			i++;
			if (s[i] && s[i] == c)
				count++;
			if (!s[i])
			{
				count++;
				break ;
			}
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

char	*store_string(const char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		i;
	int		index;

	i = 0;
	index = 0;
	str = (char **)malloc(sizeof(char *) * (string_count(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			str[index++] = store_string(&s[i++], c);
			while (s[i] && s[i] != c)
				i++;
			while (s[i] && s[i] == c)
				i++;
		}
	}
	str[index] = 0;
	return (str);
}
