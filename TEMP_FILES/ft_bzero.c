/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 05:43:10 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/01 05:45:59 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	pos;
	char	*str;

	str = (char *) s;
	pos = 0;
	while (pos < n)
	{
		*(str + pos) = 0;
		pos++;
	}
}
