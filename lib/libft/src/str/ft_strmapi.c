/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:31:16 by mmalanch          #+#    #+#             */
/*   Updated: 2017/10/30 18:31:20 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	index;

	index = -1;
	if (!s)
		return (NULL);
	if ((ret = ft_strnew(ft_strlen(s))))
		while (s[++index])
			ret[index] = (*f)(index, (char)s[index]);
	return (ret);
}
