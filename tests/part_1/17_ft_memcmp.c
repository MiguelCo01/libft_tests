/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_ft_memcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:21:43 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/10 09:14:19 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"

int sign(int x) {
    return (x > 0) - (x < 0);
}

int	main(int argc, char **argv)
{
	char	*s1;
	char	*s2;
	int		n;

	setup(argc, argv);
	describe("Comparing strings of same size and n = size");
		it("Returns 1 for string of same size and s1 > s2");
			s1 = "bbc";
			s2 = "abc";
			n = 3;
			assert_equal_int(ft_memcmp(s1, s2, n), 1, NULL);
		it("Returns 0 for string of same size and s1 = s2");
			s1 = "abc";
			s2 = "abc";
			n = 3;
			assert_equal_int(ft_memcmp(s1, s2, n), 0, NULL);
		it("Returns -1 for string of same size and s1 < s2");
			s1 = "abc";
			s2 = "bbc";
			n = 3;
			assert_equal_int(ft_memcmp(s1, s2, n), -1, NULL);
	end_describe();
	describe("Comparing strings of diff size and n = size of smaller");
		it("Returns 1 for string of same size and s1 > s2");
			s1 = "abda";
			s2 = "abc";
			n = 3;
			assert_equal_int(ft_memcmp(s1, s2, n), 1, NULL);
		it("Returns 1 for string of same size and s1 > s2");
			s1 = "abcd";
			s2 = "abc";
			n = 3;
			assert_equal_int(ft_memcmp(s1, s2, n), 0, NULL);
		it("Returns -1 for string of same size and s1 < s2");
			s1 = "abc";
			s2 = "abda";
			n = 3;
			assert_equal_int(ft_memcmp(s1, s2, n), -1, NULL);
	end_describe();
	describe("Comparing strings of diff size and n = size of bigger");
		it("Returns 1 for string of same size and s1 > s2");
			s1 = "abca";
			s2 = "abc";
			n = 4;
			assert_equal_int(sign(ft_memcmp(s1, s2, n)), 1, NULL);
	end_describe();
	describe("Handles non printable");
		it("Returns 1 for string of same size and s1 > s2");
			s1 = "ab\ta";
			s2 = "abc";
			n = 4;
			assert_equal_int(sign(ft_memcmp(s1, s2, n)), -1, NULL);
	end_describe();
	describe("Handles non printable");
		it("Returns 1 for string of same size and s1 > s2");
			int i1[3] = {1, 2, 3};
			int i2[3] = {1, 4, 2};
			n = 3 * sizeof(int);
			assert_equal_int(sign(ft_memcmp((int *)i1, (int *)i2, n)), -1, NULL);
	end_describe();

	return (test_status());
}
