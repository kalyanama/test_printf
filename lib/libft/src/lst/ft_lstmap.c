/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:38:53 by mmalanch          #+#    #+#             */
/*   Updated: 2017/11/14 14:39:01 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *tmp;

	if (!(tmp = (t_list *)ft_memalloc(sizeof(t_list*))) || !lst || !(*f))
		return (NULL);
	tmp = f(lst);
	ret = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = (t_list *)ft_memalloc(sizeof(t_list*))))
		{
			free(tmp);
			return (NULL);
		}
		tmp->next = f(lst);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (ret);
}
