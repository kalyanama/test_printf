/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:34:42 by mmalanch          #+#    #+#             */
/*   Updated: 2017/10/30 15:34:44 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*ptr;

	ptr = (char *)s;
	len = ft_strlen(ptr);
	ptr += len - 1;
	if (!c)
		return (ptr + 1);
	while (len--)
		if (*ptr == c)
			return (ptr);
		else
			ptr--;
	return (0);
}
