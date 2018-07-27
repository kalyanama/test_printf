/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:24:57 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/06 16:24:58 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printers.h"

int	print_hex(t_handler *handler, va_list args)
{
	int			chars_printed;
	size_t		value;
	char		*result;
	size_t		len;

	value = manage_length_unsigned(va_arg(args, size_t), handler->length);
	if (handler->sp == 'x' || handler->sp == 'X')
		handler->flags.hash *= value != 0;
	result = convert_base(value, HEX_BASE, handler->sp == 'X', UNSIGNED_NUM);
	len = ft_strlen(result) * check_val_prec(handler->prec, &result);
	chars_printed = 0;
	chars_printed += print_value(handler, result, len, false);
	ft_strdel(&result);
	return (chars_printed);
}
