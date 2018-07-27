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
	if (h->sp == 'c' || h->sp == '%' || !ft_strchr("diouxXcsprb%", h->sp))
		ret = print_char(h, args);
	else if (h->sp == 'd')
		ret = print_num_signed(h, args);
	else if (ft_strchr("buoxXp", h->sp))
		ret = print_num_unsigned(h, args);
	else if (h->sp == 's' || h->sp == 'p')
		ret = print_string(h, args);
	return (ret);
}