/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_ft_toupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:50:02 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/06 19:25:28 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"


void test_toupper(int c, int expected)
{
	char test_name[MAX_ERROR_MSG_LEN];

	it(formated_string(test_name, "when char is %c", c));
	printf("%d", c);
	assert_equal_int(ft_toupper(c), (unsigned char) expected, NULL);
	assert_equal_int(ft_toupper(c), toupper(c), NULL);
}

int	main(int argc, char **argv)
{
	setup(argc, argv);

	describe("transforms [a-z] to [A-Z]");
		test_toupper('a', 'A');
		test_toupper('g', 'G');
		test_toupper('z', 'Z');
	end_describe();

	describe("doesn't tranforms outside of [a-z]");
		test_toupper('A', 'A');
		test_toupper('G', 'G');
		test_toupper('Z', 'Z');
		test_toupper('0', '0');
		test_toupper('1', '1');
		test_toupper('9', '9');
		test_toupper('(', '(');
		test_toupper('-', '-');
		test_toupper('\0', '\0');
	end_describe();
	return (test_status());
}
