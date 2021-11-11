/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:19:52 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/10 20:30:27 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	pos;
	char	*dest_str;
	char	*src_str;

	dest_str = (char *)dest;
	src_str = (char *)src;
	while (pos < n)
	{
		dest_str[pos] = src_str[pos];
		if (src_str[pos] == c)
			return ((void *) &dest_str[pos + 1]);
		pos++;
	}
	return (NULL);
}
