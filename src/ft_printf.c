/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:48:38 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/08 14:48:41 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../inc/parsers.h"

static t_handler *init_handler()
{
	t_handler *handler;

	handler = (t_handler *)malloc(sizeof(t_handler));
	handler->width = 0;
	handler->precision = -1;
	handler->length = DEFAULT_LENGTH;
	handler->flags.hash = false;
	handler->flags.pad_zero = false;
	handler->flags.force_sign = false;
	handler->flags.pad_right = false;
	handler->flags.space_flag = false;

	return (handler);
}

static void parse_to_handler(const char **fmt, t_handler *handler, va_list va_args)
{
	while ((WIDTH(**fmt) || FLAG(**fmt) || PREC(**fmt) || SIZE(**fmt)) && **fmt)
	{
		while (**fmt && FLAG(**fmt))
			parse_flags(fmt, handler);
		if (**fmt && WIDTH(**fmt))
			parse_width(fmt, handler, va_args);
		if (**fmt && PREC(**fmt))
			parse_precision(fmt, handler, va_args);
		if (**fmt && SIZE(**fmt))
			parse_length(fmt, handler);
	}
	if (**fmt)
		parse_specifier(fmt, handler);
}

static int			doformat(const char **fmt, va_list ap)
{
	t_handler *handler;
	int chars_printed;

	if (!**fmt)
		return (0);
	handler = init_handler();
	parse_to_handler(fmt, handler, ap);
	chars_printed = print_arg(handler, ap, fmt);
	ft_memdel((void **) &handler);
	return (chars_printed);
}

static int			ft_printf_core(const char *fmt, va_list ap)
{
	int chars_printed;

	chars_printed = 0;
	while (*fmt)
	{
		if (*fmt == START_SPEC)
		{
			++fmt;
			chars_printed += doformat(&fmt, ap);
			fmt--; // Kostyl
		}
		else
		{
			ft_putchar(*fmt);
			chars_printed++;
		}
		fmt++;
	}
	return (chars_printed);
}

int					ft_printf(const char *format, ...)
{
	va_list	ap;
	int		done;

	va_start(ap, format);
	done = ft_printf_core(format, ap);
	va_end(ap);
	return (done);
}
