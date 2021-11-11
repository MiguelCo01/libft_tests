/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:33:36 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/09 09:54:04 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size)
	{
		*(dst + i) = *(src + i);
		if (*(src + i) == '\0')
		{
			dst[i] = '\0';
			return (i);
		}
		i++;
	}
	dst[i - 1] = '\0';
	return (ft_strlen(src));
}
