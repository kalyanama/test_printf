/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:32:39 by mmalanch          #+#    #+#             */
/*   Updated: 2017/10/30 18:32:40 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		begin;
	size_t	end;
	int		ret_len;

	if (!s)
		return (NULL);
	end = ft_strlen(s);
	begin = 0;
	while (FT_SPACE(s[begin]))
		begin++;
	while (FT_SPACE(s[end - 1]))
		end--;
	ret_len = end - begin;
	ret_len = FT_ABS(ret_len);
	s += begin;
	if ((ret = ft_strnew(ret_len)))
		ft_strncpy(ret, s, ret_len);
	return (ret);
}
