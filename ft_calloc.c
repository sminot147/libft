/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <sminot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:57:03 by sminot            #+#    #+#             */
/*   Updated: 2024/11/18 19:56:20 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptn;

	if (nmemb >= INT_MAX || size >= INT_MAX)
		return (NULL);
	size *= nmemb;
	if (size >= INT_MAX)
		return (NULL);
	ptn = malloc(size);
	if (!ptn)
		return (NULL);
	while (size--)
		ptn[size] = 0;
	return (ptn);
}
