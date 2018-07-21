/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:21:45 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/06 16:21:47 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printers.h"

int	print_octal(t_handler *handler, va_list args)
{
	int			chars_printed;
	size_t	value;
	char		*result;
	size_t		len;

	chars_printed = 0;
	value = manage_length_unsigned(va_arg(args, size_t), handler->length);
	if (!value && handler->precision)
		handler->flags.hash = value != 0 && handler->flags.hash;
	result = convert_base(value, OCTAL_BASE, handler->specifier, UNSIGNED_NUM);
	len = ft_strlen(result) * check_null_value_and_prec(handler->precision,
		&result);
	//fresh kostyl
	if (handler->precision > (int)len)
		handler->flags.hash = false;
	chars_printed += print_value(handler, result, len, false);
	ft_strdel(&result);
	return (chars_printed);
}
