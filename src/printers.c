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

int	print_arg(t_handler *curr, va_list args, const char **fmt)
{
	int	ret;

	ret = 0;
	if (curr->specifier == S_DECIMAL)
		ret = print_decimal(curr, args, SIGNED_NUM);
	else if (curr->specifier == U_DECIMAL)
		ret = print_decimal(curr, args, UNSIGNED_NUM);
	else if (curr->specifier == OCTAL)
		ret = print_octal(curr, args);
	else if (curr->specifier == HEX_LOWER || curr->specifier == HEX_UPPER)
		ret = print_hex(curr, args);
	else if (curr->specifier == CHAR)
		ret = print_char(curr, args, 0);
	else if (curr->specifier == STRING || curr->specifier == NON_PRINTABLE)
		ret = print_string(curr, args, curr->specifier == NON_PRINTABLE);
	else if (curr->specifier == POINTER)
		ret = print_pointer(curr, args);
	else if (curr->specifier == PERCENT)
		ret = print_percent(curr);
	else if (curr->specifier == BINARY)
		ret = print_binary(curr, args);
	else if (curr->specifier == INVALID_SPECIFIER && **fmt)
		ret = print_char(curr, args, *(*fmt)++);
	return (ret);
}
