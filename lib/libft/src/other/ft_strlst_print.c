/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlst_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:24:16 by mmalanch          #+#    #+#             */
/*   Updated: 2017/11/23 19:24:25 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlst_print(t_list *alst)
{
	char *arrow;

	arrow = "->";
	while (alst)
	{
		ft_putstr((char*)(alst)->content);
		ft_putstr(arrow);
		alst = (alst)->next;
	}
	ft_putendl("NULL");
}
