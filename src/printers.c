/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:46:46 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/15 16:46:49 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printers.h"

static int	print_prefix(t_handler *h, bool neg_sign)
{
	if (h->flags.hash)
	{
		if (h->sp == 'o')
			return (int)(write(STDOUT_FILENO, "0", ft_strlen("0")));
		if (h->sp == 'x' || h->sp == 'X' || h->sp == 'p')
		{
			ft_putchar('0');
			ft_putchar((char)(h->sp == 'X' ? 'X' : 'x'));
			return (2);
		}
	}
	if (h->flags.force_sign && h->sp == 'd')
		return (int)(neg_sign ? write(STDOUT_FILENO, "-", ft_strlen("-"))
							: write(STDOUT_FILENO, "+", ft_strlen("+")));
	else if (h->flags.space_flag && h->sp == 'd')
		return (int)(write(STDOUT_FILENO, " ", ft_strlen(" ")));
	return (0);
}

static int	print_precision(int prec, size_t value_len)
{
	int chars;

	chars = 0;
	while (prec > (int)value_len)
	{
		ft_putchar('0');
		chars++;
		prec--;
	}
	return (chars);
}

static int	print_width(t_handler *h, size_t value_len)
{
	int chars;

	chars = 0;
	if (h->prec > (int)value_len && h->sp != 'c')
		value_len += h->prec - value_len;
	value_len += (h->flags.force_sign || h->flags.space_flag)
					&& h->sp == 'd';
	value_len += h->flags.hash && h->sp == 'o';
	value_len += ((h->sp == 'x' || h->sp == 'X' || h->sp == 'p')
					&& h->flags.hash) * 2;
	h->flags.pad_zero *= !(h->flags.pad_right);
	while (h->width > (int)value_len)
	{
		ft_putchar((char)(h->flags.pad_zero ? '0' : ' '));
		chars++;
		h->width--;
	}
	return (chars);
}

int			print_value(t_handler *h, char *result, size_t len, bool neg_sign)
{
	int chars_printed;

	chars_printed = 0;
	chars_printed += (int)len;
	if (ft_strchr("duoxXbp", h->sp))
		h->flags.pad_zero *= h->prec == -1;
	if (h->flags.pad_right)
	{
		chars_printed += print_prefix(h, neg_sign);
		chars_printed += print_precision(h->prec, len);
		h->sp == 'c' && h->length != L ? ft_putchar(result[0])
									: ft_putstr(result);
		chars_printed += print_width(h, len);
	}
	else
	{
		chars_printed += h->flags.pad_zero ? print_prefix(h, neg_sign) : 0;
		chars_printed += print_width(h, len);
		chars_printed += h->flags.pad_zero ? 0 : print_prefix(h, neg_sign);
		chars_printed += print_precision(h->prec, len);
		h->sp == 'c' && ft_strequ(result, "\0") ? ft_putchar(result[0])
										: ft_putstr(result);
	}
	ft_strdel(&result);
	return (chars_printed);
}

int			print_conversion(t_handler *h, va_list args)
{
	int ret;

	ret = 0;
	if (h->sp == 'c' || h->sp == '%' || !ft_strchr("diouxXcsprb%", h->sp))
		ret = print_char(h, args);
	else if (h->sp == 'd')
		ret = print_num_signed(h, args);
	else if (ft_strchr("buoxXp", h->sp))
		ret = print_num_unsigned(h, args);
	else if (h->sp == 's' || h->sp == 'r')
		ret = print_string(h, args);
	return (ret);
}
