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

size_t	manage_length_unsigned(size_t val, t_length length);
ssize_t	manage_length_signed(ssize_t val, t_length length);
char	*convert_base(size_t unsgnd,
	int base, t_specifier specifier, bool is_unsigned);
char	*ft_strndup(const char *src, size_t size);
bool	check_val_prec(int prec, char **result);
size_t	get_numlen(size_t usigned_num, int base, bool is_unsigned);
void	print_num(size_t unsigned_num, bool is_unsigned);
unsigned int	count_bits(unsigned int value);

int				cmp_len(t_length curr, t_length new);


#endif
