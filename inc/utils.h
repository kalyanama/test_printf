/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:25:13 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/15 16:25:16 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include "ft_printf.h"

uintmax_t	manage_length_unsigned(uintmax_t val, t_length length);
intmax_t	manage_length_signed(intmax_t val, t_length length);
char		*convert_base(uintmax_t unsgnd,
	int base, t_specifier specifier, bool is_unsigned);
char		*ft_strndup(const char *src, size_t size);
bool		check_null_value_and_prec(int prec, char **result);
size_t		get_numlen(uintmax_t usigned_num, short base, bool is_unsigned);
void		print_num(uintmax_t unsigned_num, bool is_unsigned);
unsigned int count_bits(unsigned int value);

int cmp_len(t_length curr, t_length new);


#endif
