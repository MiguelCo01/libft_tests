/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:16:13 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/10/22 01:10:46 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

void	_verify_ft_isalnum(char c)
{
	_verify(isalnum(c), ft_isalnum(c),
		"When: char is %c Expected: %d Recieved: %d", c);
}

void	test_isalnum(void)
{
	_describe("Testing ft_isalnum");
	_verify_ft_isalnum('a' - 1);
	_verify_ft_isalnum('a');
	_verify_ft_isalnum('z' + 1);
	_verify_ft_isalnum('z');
	_verify_ft_isalnum('A' - 1);
	_verify_ft_isalnum('A');
	_verify_ft_isalnum('Z' + 1);
	_verify_ft_isalnum('Z');
	_verify_ft_isalnum('/');
	_verify_ft_isalnum('%');
	_verify_ft_isalnum('9');
	_verify_ft_isalnum('0');
	_verify_ft_isalnum('5');
}
