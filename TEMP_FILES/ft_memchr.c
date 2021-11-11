/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:46:04 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/01 13:53:38 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			pos;
	unsigned char	*search_str;
	unsigned char	search_char;

	pos = 0;
	search_str = (unsigned char *)s;
	search_char = (unsigned char) c;
	while (pos < n)
	{
		if (search_str[pos] == search_char)
			return ((void *)&search_str[pos]);
		pos++;
	}
	return (NULL);
}
