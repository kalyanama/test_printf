/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:15:38 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/15 16:15:40 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include <stdint.h>
# include <limits.h>
# include "colors.h"
# define START_SPEC '%'

typedef enum	e_length
{
	DEFAULT_LENGTH, HH, H, L, LL, J, Z, NONE
}				t_length;

typedef enum	e_specifier
{
	INVALID_SPECIFIER, BINARY,S_DECIMAL, U_DECIMAL, OCTAL, HEX_LOWER, HEX_UPPER,
	CHAR, STRING, POINTER, PERCENT, NON_PRINTABLE
}				t_specifier;

struct			s_flags
{
	bool pad_right;
	bool pad_zero;
	bool force_sign;
	bool space_flag;
	bool hash;
};

typedef struct	s_handler
{
	struct s_flags	flags;
	int				width;
	int				precision;
	t_length		length;
	t_specifier		specifier;
}				t_handler;

int				ft_printf(const char *format, ...);
//bool			valid_handler(t_handler *handler);
int				print_arg(t_handler *handler, va_list args, const char **fmt);

#endif
