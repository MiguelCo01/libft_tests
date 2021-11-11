/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_ft_isalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:50:02 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/10 20:11:08 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"





int	main(int argc, char **argv)
{
	setup(argc, argv);

	describe("return 1 if is alpha");
		it("returns 1 for a");
		assert_equal_int(ft_isalpha('a'), ft_isalnum('a'), NULL);

		it("returns 1 for z");
		assert_equal_int(ft_isalpha('z'), ft_isalnum('z'), NULL);

		it("returns 1 for Z");
		assert_equal_int(ft_isalpha('Z'), ft_isalnum('Z'), NULL);

		it("returns 1 for A");
		assert_equal_int(ft_isalpha('A'), ft_isalnum('A'), NULL);
	end_describe();

	describe("1 if is digit");
		it("returns 1 for 0");
		assert_equal_int(ft_isdigit('0'), ft_isalnum('0'), NULL);

		it("returns 1 for 9");
		assert_equal_int(ft_isdigit('9'), ft_isalnum('9'), NULL);

		it("returns 1 for 1");
		assert_equal_int(ft_isdigit('1'), ft_isalnum('1'), NULL);
	end_describe();

	describe("0 if is not digit nor alpha");
		it("returns 0 for '-'");
		assert_equal_int(ft_isalnum('-'), 0, NULL);

		it("returns 0 for ' '");
		assert_equal_int(ft_isalnum(' '), 0, NULL);

		it("returns 0 for '\\0");
		assert_equal_int(ft_isalnum('\0'), 0, NULL);
	end_describe();

	return (test_status());
}
