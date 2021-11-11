/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:56:54 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/10 20:07:55 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_char;
	int		i;

	i = 0;
	last_char = NULL;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			last_char = (char *)&s[i];
		i++;
	}
	if (c == '\0')
		last_char = (char *)&s[i];
	return (last_char);
}
