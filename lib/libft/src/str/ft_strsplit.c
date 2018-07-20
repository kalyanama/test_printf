/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:32:52 by mmalanch          #+#    #+#             */
/*   Updated: 2017/10/30 18:32:53 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (!s || !(tab = (char**)malloc(sizeof(*tab) * ft_count_words(s, c) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
		if (s[i] == c)
			i++;
		else if (s += i)
		{
			i = 0;
			while (s[i] != c && s[i])
				i++;
			if (!(tab[j] = ft_strnew(i)))
			{
				free(tab);
				return (NULL);
			}
			ft_strncpy(tab[j++], s, i);
		}
	tab[j] = 0;
	return (tab);
}
