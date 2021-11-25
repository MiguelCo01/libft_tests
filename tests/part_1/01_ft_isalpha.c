/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ft_isalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:50:02 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/24 15:36:45 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"
#include "ctype.h"

void test_isalpha(int c, int expected)
{
	char test_name[MAX_ERROR_MSG_LEN];

	it(formated_string(test_name, "when char is %c", (unsigned char) c));
	assert_equal_int(!!ft_isalpha(c), expected, NULL);
	it(formated_string(test_name, "when char is %c and comparint with original", (unsigned char) (c + 256)));
	assert_equal_int(!!ft_isalpha((c)), !!isalpha((c)), NULL);
}

int	main(int argc, char **argv)
{

	setup(argc, argv);

	describe("should return 1 if alpha");
		test_isalpha('a', 1);
		test_isalpha('A', 1);
		test_isalpha('z', 1);
		test_isalpha('Z', 1);
	end_describe();

	describe("should return 0 if not alpha");
		test_isalpha('1', 0);
		test_isalpha(' ', 0);
		test_isalpha('\0', 0);
		test_isalpha('a' - 1, 0);
		test_isalpha('A' - 1, 0);
		test_isalpha('z' + 1, 0);
		test_isalpha('Z' + 1, 0);
	end_describe();

	return (test_status());
}
