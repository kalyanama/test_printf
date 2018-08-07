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
	NONE, HH, H, L, LL, J, Z
}				t_length;

typedef struct	s_flags
{
	bool pad_right;
	bool pad_zero;
	bool force_sign;
	bool space_flag;
	bool hash;
}				t_flags;

typedef struct	s_handler
{
	t_flags		flags;
	int			width;
	int			prec;
	t_length	length;
	char		sp;
}				t_handler;

int				ft_printf(const char *format, ...);

#endif
