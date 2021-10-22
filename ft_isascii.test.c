/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:16:13 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/10/22 01:31:05 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

void	_verify_ft_isascii(int c)
{
	_verify(isascii(c), ft_isascii(c),
		"When: char is %c Expected: %d Recieved: %d", c);
}

void	test_isascii(void)
{
	_describe("Testing ft_isascii");
	_verify_ft_isascii(0);
	_verify_ft_isascii(127);
	_verify_ft_isascii(-1);
	_verify_ft_isascii(0);
	_verify_ft_isascii(1);
	_verify_ft_isascii(128);
	_verify_ft_isascii(-500);
}
