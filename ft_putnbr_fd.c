/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:54:40 by sminot            #+#    #+#             */
/*   Updated: 2024/11/20 12:31:31 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_positive(int nb, char *base, int fd)
{
	if (nb)
	{
		ft_putnbr_positive(nb / 10, base, fd);
		write(fd, &base[nb % 10], 1);
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	char	*base;

	base = "0123456789";
	if (!nb)
		write(fd, "0", 1);
	else if (nb == INT_MIN)
		write(fd, "-2147483648", 11);
	else if (nb < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_positive(-nb, base, fd);
	}
	else
		ft_putnbr_positive(nb, base, fd);
}
