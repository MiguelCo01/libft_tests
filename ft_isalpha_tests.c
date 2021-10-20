/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:16:13 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/10/21 00:20:25 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include "stdio.h"
#include "assert.h"
#include "ctype.h"

static int	g_test_number;

void	_verify_ft_isalpha(char c)
{
	int	expected;
	int	actual;

	g_test_number = g_test_number + 1;
	expected = isalpha(c);
	actual = ft_isalpha(c);
	if (expected == actual)
	{
		printf("%d - OK\n", g_test_number);
	}
	else
	{
		printf("%d - NOK - When: char is %c Expected: %d Recieved: %d\n",
			g_test_number, c, expected, actual);
	}
}

int	test_isalpha(void)
{
	g_test_number = 0;
	printf("Testing ft_isalpha...\n");
	_verify_ft_isalpha('a');
	_verify_ft_isalpha('b');
	return (0);
}
