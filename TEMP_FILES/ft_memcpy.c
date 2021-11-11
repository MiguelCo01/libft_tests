/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:04:56 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/01 14:08:50 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	pos;
	char	*dest_str;
	char	*src_str;

	dest_str = (char *)dest;
	src_str = (char *)src;
	pos = 0;
	while (pos < n)
	{
		dest_str[pos] = src_str[pos];
		pos++;
	}
	return (dest);
}
