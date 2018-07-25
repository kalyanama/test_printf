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

# define BINARY_BASE 2
# define DECIMAL_BASE 10
# define OCTAL_BASE 8
# define HEX_BASE 16
# define UNSIGNED_NUM 1
# define SIGNED_NUM !UNSIGNED_NUM
# define ZERO "0"

int print_binary(t_handler *handler, va_list args);
int	print_decimal(t_handler *handler, va_list args, bool is_unsigned);
int	print_octal(t_handler *handler, va_list args);
int	print_hex(t_handler *handler, va_list args);
int	print_char(t_handler *handler, va_list args, char invalid_spec);
int print_string(t_handler *h, va_list args, bool non_printable);
int	print_pointer(t_handler *handler, va_list args);
int	print_percent(t_handler *handler);
char    *get_wchar(wchar_t value);
char    *get_wstr(wchar_t *value, int precision);

int	print_prefix(t_handler *h, bool neg_sign);
int	print_value(t_handler *h, char *result, size_t len, bool neg_sign);
int	print_width(t_handler *h, size_t value_len);
int	print_precision(int prec, size_t value_len);

#endif
