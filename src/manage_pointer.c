/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:19:16 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/06 16:19:18 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printers.h"

int	print_pointer(t_handler *curr, va_list args)
{
	int chars_printed;

	curr->length = NONE;
	curr->flags.hash = true;
	chars_printed = print_hex(curr, args);
	return (chars_printed);
}
