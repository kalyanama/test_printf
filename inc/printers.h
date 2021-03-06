/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:22:59 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/15 16:23:02 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRINTERS_H
# define FT_PRINTF_PRINTERS_H

# include "ft_printf.h"
# include "utils.h"

# define DECIMAL_BASE 10
# define UNSIGNED_NUM 1
# define SIGNED_NUM !UNSIGNED_NUM

int		print_num_unsigned(t_handler *handler, va_list args);
int		print_num_signed(t_handler *handler, va_list args);
int		print_char(t_handler *h, va_list args);
int		print_string(t_handler *h, va_list args);

int		print_value(t_handler *h, char *result, size_t len, bool neg_sign);
int		print_conversion(t_handler *h, va_list args);

char	*get_wchar(wchar_t value);

#endif
