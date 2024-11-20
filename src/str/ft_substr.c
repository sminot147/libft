/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <sminot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:24:33 by sminot            #+#    #+#             */
/*   Updated: 2024/11/05 13:24:33 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*str;

	i = 0;
	while (s[i] && i < start + len)
		i++;
	if (i < start)
	{
		str = malloc(1 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc((i - start + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	j = -1;
	while (s[start + ++j] && j < len)
		str[j] = s[start + j];
	str[j] = '\0';
	return (str);
}