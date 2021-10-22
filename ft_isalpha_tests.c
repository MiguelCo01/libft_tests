/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:16:13 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/10/22 01:09:07 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

void	_verify_ft_isalpha(char c)
{
	_verify(isalpha(c), ft_isalpha(c),
		"When: char is %c Expected: %d Recieved: %d", c);
}

void	test_isalpha(void)
{
	_describe("Testing ft_isalpha");
	_verify_ft_isalpha('a' - 1);
	_verify_ft_isalpha('a');
	_verify_ft_isalpha('z' + 1);
	_verify_ft_isalpha('z');
	_verify_ft_isalpha('A' - 1);
	_verify_ft_isalpha('A');
	_verify_ft_isalpha('Z' + 1);
	_verify_ft_isalpha('Z');
}
