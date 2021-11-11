/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_ft_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:28:49 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/08 09:50:27 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"

void	test_atoi(char* s1, int expected)
{
	char formated_error[MAX_ERROR_MSG_LEN];

	it(formated_string(formated_error, "When s1 is %s", s1));
		assert_equal_int(ft_atoi(s1), expected, NULL);
}

int	main(int argc, char **argv)
{
	setup(argc, argv);

	describe("handles positive numbers");
		test_atoi("1", 1);
		test_atoi("20", 20);
		test_atoi("4587", 4587);
		test_atoi("+4587", 4587);
	end_describe();

	describe("handles zero");
		test_atoi("0", 0);
	end_describe();

	describe("handles negative numbers");
		test_atoi("-1", -1);
		test_atoi("-20", -20);
		test_atoi("-4587", -4587);
	end_describe();

	describe("handles string starting with space");
		test_atoi(" 1", 1);
		test_atoi(" -1", -1);
		test_atoi("   -1", -1);
		test_atoi("\f\n\r\t\v1", 1);
	end_describe();

	describe("error with more than one (plus/minus) sign");
		test_atoi("-+1", 0);
		test_atoi("++1", 0);
		test_atoi("--1", 0);
		test_atoi(" -+1", 0);
	end_describe();

	describe("error with more than one (plus/minus) sign");
		test_atoi("-+1", 0);
		test_atoi("++1", 0);
		test_atoi("--1", 0);
		test_atoi(" -+1", 0);
	end_describe();

	describe("stops reading after the first non digit");
		test_atoi("  100a98", 100);
		test_atoi("  100aaaa", 100);
		test_atoi("  as100aaaa", 0);
		test_atoi("  -as100aaaa", 0);
	end_describe();


	return (test_status());
}
