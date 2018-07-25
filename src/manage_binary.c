/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:07:01 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/25 13:07:02 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printers.h"

int	print_binary(t_handler *handler, va_list args)
{
	int		chars_printed;
	size_t	value;
	char	*result;
	size_t	len;

	chars_printed = 0;
	value = manage_length_unsigned(va_arg(args, size_t), handler->length);
	result = convert_base(value, BINARY_BASE, handler->specifier, UNSIGNED_NUM);
	len = ft_strlen(result) * check_val_prec(handler->precision, &result);
	chars_printed += print_value(handler, result, len, false);
	ft_strdel(&result);
	return (chars_printed);
}
