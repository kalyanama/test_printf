/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:34:35 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/15 16:34:36 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printers.h"

#define MASK1 192
#define MASK2 224
#define MASK3 240
#define SIX_BITS(v) (((v) & 63) + 128)

static unsigned int	wchar_max_bytes(unsigned int bits)
{
	if (bits <= 7 && MB_CUR_MAX >= 1)
		return (1);
	else if (bits > 7 && bits <= 11 && MB_CUR_MAX >= 2)
		return (2);
	else if (bits > 11 && bits <= 16 && MB_CUR_MAX >= 3)
		return (3);
	else if (bits > 16 && MB_CUR_MAX >= 4)
		return (4);
	return (1);
}

char				*get_wchar(wchar_t value)
{
	unsigned char	*ret;
	unsigned int	bytes;

	if (value == 0)
		return (ft_strdup("\0"));
	bytes = wchar_max_bytes(count_bits((unsigned int)value));
	ret = ft_memalloc(5);
	ret[0] = (unsigned char) (bytes == 1 ? value : SIX_BITS(value));
	if (bytes == 2)
		ret[1] = (unsigned char)((value >> 6) + MASK1);
	else if (bytes == 3)
	{
		ret[1] = (unsigned char)(SIX_BITS(value >> 6));
		ret[2] = (unsigned char)((value >> 12) + MASK2);
	}
	else if (bytes == 4)
	{
		ret[1] = (unsigned char)(SIX_BITS(value >> 6));
		ret[2] = (unsigned char)(SIX_BITS(value >> 12));
		ret[3] = (unsigned char)((value >> 18) + MASK3);
	}
	return (ft_strrev((char *)ret));
}

int print_char(t_handler *h, va_list args)
{
	int		chars_printed;
	char	*value;
	size_t len;

	chars_printed = 0;
	if (h->length == L && h->sp == 'c')
		value = get_wchar(va_arg(args, wchar_t));
	else
	{
		value = ft_strnew(1);
		value[0] = h->sp == 'c' ? (unsigned char) va_arg(args, int) : (unsigned char) h->sp;
	}
	len = ft_strequ(value, "\0") ? 1 : ft_strlen(value);
	h->prec = -1;
	chars_printed += print_value(h, value, len, false);
	ft_strdel(&value);
	return (chars_printed);
}