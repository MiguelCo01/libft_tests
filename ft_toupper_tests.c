/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:16:13 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/10/22 01:21:25 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

void	_verify_ft_toupper(char c)
{
	_verify(toupper(c), ft_toupper(c),
		"When: char is %c Expected: %d Recieved: %d", c);
}

void	test_toupper(void)
{
	_describe("Testing ft_toupper");
	_verify_ft_toupper('a' - 1);
	_verify_ft_toupper('a');
	_verify_ft_toupper('z' + 1);
	_verify_ft_toupper('z');
	_verify_ft_toupper('A' - 1);
	_verify_ft_toupper('A');
	_verify_ft_toupper('Z' + 1);
	_verify_ft_toupper('Z');
}
