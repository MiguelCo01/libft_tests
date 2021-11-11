/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 05:48:16 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/10 09:37:28 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	mem_size;

	if (nmemb == 0 || size == 0)
		return (NULL);
	mem_size = nmemb * size;
	if (mem_size > __INT_MAX__)
		return (NULL);
	return (malloc(mem_size));
}
