/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <sminot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:27:30 by sminot            #+#    #+#             */
/*   Updated: 2024/11/18 19:59:37 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	c2;

	s2 = (unsigned char *)s;
	c2 = c;
	while (n--)
	{
		if (*s2 == c2)
			return (s2);
		else
			s2++;
	}
	return (0);
}
