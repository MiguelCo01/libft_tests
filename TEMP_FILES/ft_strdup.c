/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 03:01:25 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/09 09:28:55 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	str_size;
	char	*result;

	str_size = ft_strlen(s);
	result = (char *)malloc(str_size);
	if (result == NULL)
	{
		return (result);
	}
	ft_memcpy(result, s, str_size);
	return (result);
}
