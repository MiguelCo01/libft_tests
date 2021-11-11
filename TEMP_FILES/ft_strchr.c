/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 20:22:07 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/10/31 20:47:32 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	position;

	position = 0;
	while (s[position] != (unsigned char) c && s[position] != '\0')
		position++;
	if (s[position] == (unsigned char) c)
		return ((char *) &s[position]);
	else
		return (0);
}
