/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_ft_tolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:50:02 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/08 15:37:29 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"


void test_tolower(int c, int expected)
{
	char test_name[MAX_ERROR_MSG_LEN];

	it(formated_string(test_name, "when char is %c", c));
	printf("%d", c);
	assert_equal_int(ft_tolower(c), (unsigned char) expected, NULL);
	assert_equal_int(ft_tolower(c), tolower(c), NULL);
}

int	main(int argc, char **argv)
{
	setup(argc, argv);

	describe("transforms [A-Z] to [a-z]");
		test_tolower('A', 'a');
		test_tolower('G', 'g');
		test_tolower('Z', 'z');
	end_describe();

	describe("doesn't tranforms outside of [A-Z]");
		test_tolower('a', 'a');
		test_tolower('g', 'g');
		test_tolower('z', 'z');
		test_tolower('0', '0');
		test_tolower('1', '1');
		test_tolower('9', '9');
		test_tolower('(', '(');
		test_tolower('-', '-');
		test_tolower('\0', '\0');
	end_describe();
	return (test_status());
}
