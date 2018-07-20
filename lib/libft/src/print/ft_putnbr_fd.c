/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 18:44:09 by mmalanch          #+#    #+#             */
/*   Updated: 2017/09/26 18:44:11 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int nb, int fd)
{
	int res;

	if (nb == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		nb -= 2000000000;
	}
	if (nb < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
	}
	if (nb / 10 != 0)
		ft_putnbr_fd(nb / 10, fd);
	res = nb % 10 + 48;
	write(fd, &res, 1);
}
