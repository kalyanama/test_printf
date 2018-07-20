/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:28:28 by mmalanch          #+#    #+#             */
/*   Updated: 2018/05/24 16:28:30 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "./libft.h"
# define BUFF_SIZE 32
# define READ_SUCCESS 1
# define READ_ERROR -1
# define READ_FINISHED 0
# define GNL_ERROR(x) if (x) return (READ_ERROR);
# define MEM_CHECK(x) if (!(x)) return (READ_ERROR);
# define NEW_LINE 10

int		get_next_line(const int fd, char **line);
#endif
