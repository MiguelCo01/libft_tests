/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:16:13 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/10/22 01:36:34 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

void	_verify_ft_isprint(int c)
{
	_verify(isprint(c), ft_isprint(c),
		"When: char is %c Expected: %d Recieved: %d", c);
}

void	test_isprint(void)
{
	_describe("Testing ft_isprint");
	_verify_ft_isprint(31);
	_verify_ft_isprint(127);
	_verify_ft_isprint(126);
	_verify_ft_isprint(32);
	_verify_ft_isprint(50);
}
