/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:40:03 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/15 16:40:05 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printers.h"

static int	print_signed(t_handler *h, va_list args)
{
	intmax_t	value;
	char		*result;
	size_t		len;
	int			chars;

	chars = 0;
	value = manage_length_signed(va_arg(args, intmax_t), h->length);
	result = convert_base((uintmax_t)value,
						DECIMAL_BASE, h->specifier, SIGNED_NUM);
	len = ft_strlen(result) * check_null_value_and_prec(h->precision, &result);
	h->flags.force_sign = h->flags.force_sign || value < 0;
	//TODO smth with this shit
	h->flags.space_flag = h->flags.space_flag
						&& !h->flags.force_sign && h->precision == -1;
	if (h->flags.space_flag)
		ft_putchar(' ');
	len += h->flags.space_flag;
	chars += print_value(h, result, len, value < 0);
	ft_strdel(&result);
	return (chars);
}

static int	print_unsigned(t_handler *h, va_list args)
{
	uintmax_t	value;
	char		*result;
	size_t		len;
	int			chars;

	chars = 0;
	value = manage_length_unsigned(va_arg(args, uintmax_t), h->length);
	result = convert_base(value, DECIMAL_BASE, h->specifier, UNSIGNED_NUM);
	len = ft_strlen(result) * check_null_value_and_prec(h->precision, &result);
	chars += print_value(h, result, len, false);
	ft_strdel(&result);
	return (chars);
}

int			print_decimal(t_handler *handler, va_list args, bool is_unsigned)
{
	int chars_printed;

	chars_printed = 0;
	if (is_unsigned)
		chars_printed += print_unsigned(handler, args);
	else
		chars_printed += print_signed(handler, args);
	return (chars_printed);
}
