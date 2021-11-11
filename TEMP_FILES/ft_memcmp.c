/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:56:13 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/01 14:03:24 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			pos;
	unsigned char	*s1_str;
	unsigned char	*s2_str;

	s1_str = (unsigned char *)s1;
	s2_str = (unsigned char *)s2;
	pos = 0;
	while (pos < n)
	{
		if (s1_str[pos] != s2_str[pos])
			return (s1_str[pos] - s2_str[pos]);
		pos++;
	}
	return (0);
}
