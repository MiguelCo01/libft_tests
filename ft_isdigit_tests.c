/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:16:13 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/10/22 01:10:21 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft_tests.h"

void	_verify_ft_isdigit(char c)
{
	_verify(isdigit(c), ft_isdigit(c),
		"When: char is %c Expected: %d Recieved: %d", c);
}

void	test_isdigit(void)
{
	_describe("Testing ft_isdigit");
	_verify_ft_isdigit('0' - 1);
	_verify_ft_isdigit('0');
	_verify_ft_isdigit('0' + 1);
	_verify_ft_isdigit('9');
	_verify_ft_isdigit('9' - 1);
	_verify_ft_isdigit('9' + 1);
	_verify_ft_isdigit('a');
	_verify_ft_isdigit('A');
	_verify_ft_isdigit('z');
	_verify_ft_isdigit('Z');
}
