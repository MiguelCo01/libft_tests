/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 03:14:12 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/10 19:48:00 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	while (dst_len < (size))
	{
		if (*(dst + dst_len) == '\0')
			break ;
		dst_len++;
	}
	if (dst_len == size)
		return (size + ft_strlen(src));
	src_len = 0;
	while ((src_len + dst_len < (size - 1)))
	{
		*(dst + dst_len + src_len) = *(src + src_len);
		if (*(dst + dst_len + src_len) == '\0')
			break ;
		src_len++;
	}
	*(dst + dst_len + src_len) = '\0';
	return (dst_len + ft_strlen(src));
}
