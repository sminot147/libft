/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:10:06 by sminot            #+#    #+#             */
/*   Updated: 2024/11/18 20:23:03 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	while (s1[len1])
		len1++;
	len2 = 0;
	while (s2[len2])
		len2++;
	str = malloc((len1 + len2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < len1)
		str[i] = s1[i];
	i--;
	while (++i <= (len1 + len2 + 1))
		str[i] = s2[i - len1];
	return (str);
}
