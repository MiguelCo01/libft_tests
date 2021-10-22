/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:16:13 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/10/22 01:10:06 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft_tests.h"

void	_verify_ft_tolower(char c)
{
	_verify(tolower(c), ft_tolower(c),
		"When: char is %c Expected: %d Recieved: %d", c);
}

void	test_tolower(void)
{
	_describe("Testing ft_tolower");
	_verify_ft_tolower('a' - 1);
	_verify_ft_tolower('a');
	_verify_ft_tolower('z' + 1);
	_verify_ft_tolower('z');
	_verify_ft_tolower('A' - 1);
	_verify_ft_tolower('A');
	_verify_ft_tolower('Z' + 1);
	_verify_ft_tolower('Z');
}
