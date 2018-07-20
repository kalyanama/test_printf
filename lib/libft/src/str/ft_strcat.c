/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 19:21:27 by mmalanch          #+#    #+#             */
/*   Updated: 2017/09/26 19:21:29 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	dlen;

	dlen = ft_strlen(dest);
	while (*src)
	{
		dest[dlen] = *src++;
		dlen++;
	}
	dest[dlen] = '\0';
	return (dest);
}
