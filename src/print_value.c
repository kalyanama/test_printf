/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 17:53:24 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/25 17:53:26 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printers.h"

int	print_prefix(t_handler *h, bool neg_sign)
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

int	print_precision(int prec, size_t value_len)
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

int	print_width(t_handler *h, size_t value_len)
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

int	print_value(t_handler *h, char *result, size_t len, bool neg_sign)
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
		ft_putstr(result);
		chars_printed += print_width(h, len);
	}
	else
	{
		chars_printed += h->flags.pad_zero ? print_prefix(h, neg_sign) : 0;
		chars_printed += print_width(h, len);
		chars_printed += h->flags.pad_zero ? 0 : print_prefix(h, neg_sign);
		chars_printed += print_precision(h->prec, len);
		ft_putstr(result);
	}
	return (chars_printed);
}

//Error (line 78): line has 91 characters
//Error (line 79): line has 90 characters
