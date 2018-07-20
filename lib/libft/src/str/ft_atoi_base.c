/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:32:24 by mmalanch          #+#    #+#             */
/*   Updated: 2017/11/22 13:32:27 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_base(char c, int base)
{
	if (base < 2 || base > 16 || !c)
		return (0);
	if (ft_isalpha(c))
		return ((c > 64 && c < 55 + base) || (c > 96 && c < 87 + base));
	if (ft_isdigit(c))
		return (c < 48 + base);
	return (0);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int	res;
	int	sign;

	res = 0;
	if (str_base < 2 || str_base > 16 || !str)
		return (0);
	while (FT_EXSPACE(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_in_base(*str, str_base))
	{
		if (*str - 48 < 10)
			res = res * str_base + *str - 48;
		else
			res = res * str_base + *str + 10 - (FT_LCASE(*str) ? 97 : 65);
		str++;
	}
	if (str_base == 10)
		res *= sign;
	return ((int)res);
}
