/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 02:34:26 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/02 02:57:11 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_str;
	char	*src_str;

	i = 0;
	dest_str = (char *)dest;
	src_str = (char *)src;
	if (src_str < dest_str)
	{
		while ((int)n >= 0)
		{
			n--;
			*(dest_str + n) = *(src_str + n);
		}
	}
	else
	{
		while (i < n)
		{
			*(dest_str + i) = *(src_str + i);
			i++;
		}
	}
	return (dest);
}
