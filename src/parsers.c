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
		handler->prec = va_arg(args, int);
		if (handler->prec < 0)
			handler->prec = -1;
	}
	else
	{
		while (**fmt == '0')
			++*fmt;
		if (ft_isdigit(**fmt))
		{
			handler->prec = ft_atoi(*fmt);
			*fmt += ft_numlen(handler->prec) + (handler->prec < 0);
		}
		else
			handler->prec = 0;
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
		handler->length = NONE;
}

void	parse_specifier(const char **fmt, t_handler *handler)
{
	if (ft_strchr("DOUCSp", **fmt))
	{
		handler->length = L;
		handler->sp = (char)ft_tolower(**fmt);
	}
	else if (**fmt == 'i')
		handler->sp = 'd';
	else
		handler->sp = **fmt;
	(*fmt)++;
}
