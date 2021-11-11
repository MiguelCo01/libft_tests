/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 04:39:38 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/01 04:57:42 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		((char *) s)[pos] = (unsigned char) c;
		pos++;
	}
	return (s);
}
