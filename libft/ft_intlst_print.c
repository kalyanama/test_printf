/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlst_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:23:51 by mmalanch          #+#    #+#             */
/*   Updated: 2017/11/23 19:23:55 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_intlst_print(t_list *list)
{
	t_list	*current;
	char	*arrow;

	current = list;
	arrow = "->";
	while (current)
	{
		ft_putnbr(*(int*)current->content);
		ft_putstr(arrow);
		current = current->next;
	}
	ft_putendl("NULL");
}
