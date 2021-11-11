/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:16:26 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/10 20:28:00 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (ft_strncmp(big + i, little, ft_strlen(little)) == 0
			&& i + ft_strlen(little) < len)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
