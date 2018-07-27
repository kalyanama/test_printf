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

int print_conversion(t_handler *h, va_list args)
{
	int ret;

	ret = 0;
	if (ft_strchr("cC", h->sp) || !ft_strchr("dDioOuUxXcCsSprb%", h->sp))
		ret = print_char(h, args);
	else if (ft_strchr("dDi", h->sp))
		ret = print_decimal(h, args, SIGNED_NUM);
	else if (ft_strchr("uU", h->sp))
		ret = print_decimal(h, args, UNSIGNED_NUM);
	else if (ft_strchr("oO", h->sp))
		ret = print_octal(h, args);
	else if (ft_strchr("xX", h->sp))
		ret = print_hex(h, args);
	else if (ft_strchr("sSr", h->sp))
		ret = print_string(h, args);
	else if (h->sp == 'p')
		ret = print_pointer(h, args);
	else if (h->sp == '%')
		ret = print_percent(h);
	else if (h->sp == 'b')
		ret = print_binary(h, args);
	return (ret);
}