/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 05:27:37 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/01 06:08:29 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	ft_atoi(const char *nptr)
{
	int	pos;
	int	value;
	int	sign;

	(void) nptr;
	pos = 0;
	value = 0;
	sign = 1;
	while (is_space(nptr[pos]))
		pos++;
	if (nptr[pos] == '-' || nptr[pos] == '+')
	{
		if (nptr[pos] == '-')
			sign = -1;
		pos++;
	}
	while (ft_isdigit(nptr[pos]))
	{
		value = value * 10 + nptr[pos] - 48;
		pos++;
	}
	return (value * sign);
}
