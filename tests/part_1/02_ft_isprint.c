/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_ft_isprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:50:02 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/06 18:23:26 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"
#include "ctype.h"

void test_isprint(char c, int expected)
{
	char test_name[MAX_ERROR_MSG_LEN];

	it(formated_string(test_name, "when char is %c", c));
	assert_equal_int(!!ft_isprint(c), expected, NULL);
	assert_equal_int(!!ft_isprint(c), !!isprint(c), NULL);
}


int	main(int argc, char **argv)
{
	setup(argc, argv);

	describe("if is printable returns 1");
		test_isprint(32, 1);
		test_isprint(126, 1);
		test_isprint(100, 1);
	end_describe();

	describe("if is not printable returns 0");
		test_isprint(31, 0);
		test_isprint(127, 0);
		test_isprint(128, 0);
		test_isprint(-32, 0);
	end_describe();
	return (test_status());
}
