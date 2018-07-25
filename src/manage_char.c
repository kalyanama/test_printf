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

static unsigned int wchar_max_bytes(unsigned int bits)
{
	if (bits <= 7 && MB_CUR_MAX >= 1)
		return (1);
	else if (bits > 7 && bits <= 11 && MB_CUR_MAX >=2)
		return (2);
	else if (bits > 11 && bits <= 16 && MB_CUR_MAX >=3)
		return (3);
	else
		return (4);
}
char * get_wchar(wchar_t value)
{
	unsigned char *ret;
	unsigned int bytes;

	if (0 == value)
		return ("\0");
	bytes = wchar_max_bytes(count_bits((unsigned int) value));
	ret = ft_memalloc(5);
	if (bytes == 1)
		ret[0] = (unsigned char)value;
	else if (bytes == 2)
	{
		ret[0] = (unsigned char)(SIX_BITS(value));
		ret[1] = (unsigned char)((value >> 6) + MASK1);
	}
	else if (bytes == 3)
	{
		ret[0] = (unsigned char)(SIX_BITS(value));
		ret[1] = (unsigned char)(SIX_BITS(value >> 6));
		ret[2] = (unsigned char)((value >> 12) + MASK2);
	}
	else if (bytes == 4)
	{
		ret[0] = (unsigned char)(SIX_BITS(value));
		ret[1] = (unsigned char)(SIX_BITS(value >> 6));
		ret[2] = (unsigned char)(SIX_BITS(value >> 12));
		ret[3] = (unsigned char)((value >> 18) + MASK3);
	}
	return (ft_strrev((char *)ret));
}

int	print_char(t_handler *curr, va_list args, char invalid_spec)
{
	int		chars_printed;
	char	value;


	chars_printed = 0;
	if (curr->length == L && curr->specifier == CHAR && MB_CUR_MAX != 1)
		chars_printed += print_string(curr, args, false);
	else
	{
		value = invalid_spec ? invalid_spec : (unsigned char)va_arg(args, int);
		if (curr->flags.pad_right)
		{
			ft_putchar(value);
			chars_printed++;
			chars_printed += print_width(curr, 1);
		}
		else
		{
			chars_printed += print_width(curr, 1);
			ft_putchar(value);
			chars_printed++;
		}
	}
	return (chars_printed);
}
