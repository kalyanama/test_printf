/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:29:51 by mmalanch          #+#    #+#             */
/*   Updated: 2017/10/30 18:29:52 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		index;

	index = -1;
	if (!s)
		return (NULL);
	if ((ret = ft_strnew(ft_strlen(s))) && *f)
		while (s[++index])
			ret[index] = (*f)((char)s[index]);
	return (ret);
}
