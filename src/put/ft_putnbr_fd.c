/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:54:40 by sminot            #+#    #+#             */
/*   Updated: 2024/11/25 18:46:40 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_put_pos_nb(long int nb, char *base, int fd, size_t len_base)
{
	ssize_t	nb_char_writed;

	if (nb > 9)
	{
		nb_char_writed = ft_put_pos_nb(nb / len_base, base, fd, len_base);
		if (nb_char_writed == -1)
			return (-1);
		if (write(fd, &base[nb % 10], 1) != 1)
			return (-1);
		return (++nb_char_writed);
	}
	else
	{
		if (write(fd, &base[nb % 10], 1) != 1)
			return (-1);
		return (1);
	}
}

static int	ft_base_is_valable(char *base, int len_base)
{
	int	i;
	int	j;

	i = 0;
	if (len_base <= 1)
		return (-1);
	while (i < len_base)
	{
		if (base [i] == '-' || base[i] == '+')
			return (-1);
		j = i + 1;
		while (j < len_base)
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

//ne fonctoinne pas avec LONG_INT_MIN
ssize_t	putnbr_base_fd(long int nb, char *base, int fd)
{
	ssize_t	nb_char_writed;
	size_t	len_base;

	len_base = ft_strlen(base);
	if (ft_base_is_valable(base, len_base) == -1)
		return (-1);
	if (nb < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		nb_char_writed = ft_put_pos_nb(-nb, base, fd, len_base);
		if (nb_char_writed == -1)
			return (-1);
		return (++nb_char_writed);
	}
	else
		return (ft_put_pos_nb(nb, base, fd, len_base));
}

ssize_t	ft_putnbr_fd(int nb, int fd)
{
	return (ft_putnbr_in_base_fd(nb, "0123456789", fd));
}
