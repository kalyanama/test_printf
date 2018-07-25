/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:28:21 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/06 16:28:23 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <form.h>
#include "../inc/parsers.h"

void	parse_width(const char **fmt, t_handler *handler, va_list args)
{
	if (**fmt == '*')
	{
		++*fmt;
		handler->width = va_arg(args, int);
		if (handler->width < 0)
			handler->flags.pad_right = true;
		handler->width = FT_ABS(handler->width);
	}
	else
	{
		handler->width = ft_atoi(*fmt);
		*fmt += ft_numlen(handler->width);
	}
}

void	parse_precision(const char **fmt, t_handler *handler, va_list args)
{
	++*fmt;
	if (**fmt == '*')
	{
		++*fmt;
		handler->precision = va_arg(args, int);
		if (handler->precision < 0)
			handler->precision = -1;
	}
	else
	{
		while (**fmt == '0')
			++*fmt;
		if (ft_isdigit(**fmt))
		{
			handler->precision = ft_atoi(*fmt);
			*fmt += ft_numlen(handler->precision) + (handler->precision < 0);
		}
		else
			handler->precision = 0;
	}
}

void	parse_flags(const char **fmt, t_handler *handler)
{
	if (**fmt == '-')
		handler->flags.pad_right = true;
	if (**fmt == '0')
		handler->flags.pad_zero = true;
	if (**fmt == '+')
		handler->flags.force_sign = true;
	if ((**fmt == ' '))
		handler->flags.space_flag = true;
	if (**fmt == '#')
		handler->flags.hash = true;
	(*fmt)++;
}

void	parse_length(const char **fmt, t_handler *handler)
{
	if (**fmt == 'h' && *(*fmt + 1) == 'h')
	{
		if (cmp_len(handler->length, HH) > 0)
			handler->length = HH;
		*fmt += 2;
	}
	else if (**fmt == 'l' && *(*fmt + 1) == 'l')
	{
		if (cmp_len(handler->length, LL) > 0)
			handler->length = LL;
		*fmt += 2;
	}
	else if (SIZE(**fmt))
	{
		if (**fmt == 'h' && (cmp_len(handler->length, H) >= 0))
			handler->length = handler->length == H ? HH : H;
		else if (**fmt == 'l' && (cmp_len(handler->length, L) >= 0))
			handler->length = handler->length == L ? LL : L;
		else if (**fmt == 'j' && (cmp_len(handler->length, J) > 0))
			handler->length = J;
		else if (**fmt == 'z' && (cmp_len(handler->length, Z) > 0))
			handler->length = Z;
		(*fmt)++;
	}
	else
		handler->length = DEFAULT_LENGTH;
}

void	parse_specifier(const char **fmt, t_handler *handler)
{
	if (ft_strchr("DOUCS", **fmt))
		handler->length = L;
	if (**fmt == 'd' || **fmt == 'i' || **fmt == 'D')
		handler->specifier = S_DECIMAL;
	else if (**fmt == 'u' || **fmt == 'U')
		handler->specifier = U_DECIMAL;
	else if (**fmt == 'o' || **fmt == 'O')
		handler->specifier = OCTAL;
	else if (**fmt == 'x')
		handler->specifier = HEX_LOWER;
	else if (**fmt == 'X')
		handler->specifier = HEX_UPPER;
	else if (**fmt == 'c' || **fmt == 'C')
		handler->specifier = CHAR;
	else if (**fmt == 's' || **fmt == 'S')
		handler->specifier = STRING;
	else if (**fmt == 'p')
		handler->specifier = POINTER;
	else if (**fmt == '%')
		handler->specifier = PERCENT;
	else if (**fmt == 'b')
		handler->specifier = BINARY;
	else if (**fmt == 'r')
		handler->specifier = NON_PRINTABLE;
	else if (**fmt)
		handler->specifier = INVALID_SPECIFIER;
	if (handler->specifier != INVALID_SPECIFIER)
		(*fmt)++;
}

// Error (line 72): function parse_length has 26 lines
// Error (line 102): function parse_specifier has 28 lines
