/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:42:40 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/15 16:42:42 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printers.h"

int	print_percent(t_handler *handler)
{
	int chars;

	chars = 0;
	handler->prec = -1;
	handler->flags.force_sign = false;
	chars += print_value(handler, "%", ft_strlen("%"), false);
	return (chars);
}
