/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_ft_strncmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:50:02 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/10 10:24:24 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"

int sign(int x) {
    return (x > 0) - (x < 0);
}

void	test_strncmp(char* s1, char *s2, size_t n, int expected)
{
	char formated_error[MAX_ERROR_MSG_LEN];

	it(formated_string(formated_error, "When s1 is '%s' and s2 = '%s' and comparing %d chars", s1, s2, n));
		assert_equal_int(sign(ft_strncmp(s1, s2, n)), sign(expected), NULL);
		assert_equal_int(sign(ft_strncmp(s1, s2, n)), sign(strncmp(s1, s2, n)), "SYS");

}

int	main(int argc, char **argv)
{
	setup(argc, argv);

	describe("returns positive if s1 > s2");
		test_strncmp("baa", "aaa", 3, 1);
		test_strncmp("aba", "aaa", 3, 1);
		test_strncmp("aab", "aaa", 3, 1);
	end_describe();

	describe("returns negative if s1 < s2");
		test_strncmp("aaa", "baa", 3, -1);
		test_strncmp("aaa", "aba", 3, -1);
		test_strncmp("aaa", "aab", 3, -1);
	end_describe();
	describe("returns 0 if s1 == s2");
		test_strncmp("", "", 3, 0);
		test_strncmp("a", "a", 3, 0);
		test_strncmp("aa", "aa", 3, 0);
		test_strncmp("aaa", "aaa", 3, 0);
	end_describe();
	describe("able to compare string of different size");
		test_strncmp("", "a", 2, -97);
		test_strncmp("a", "aa", 2, -97);
		test_strncmp("a", "", 2, 97);
		test_strncmp("aa", "a", 2, 97);
	end_describe();

	describe("able to compare if n smaller than str size");
		test_strncmp("a", "aa", 1, 0);
		test_strncmp("ab", "aaa", 2, 1);
		test_strncmp("aa", "a", 1, 0);
		test_strncmp("aaa", "ba", 2, -1);
	end_describe();

	describe("able to compare if n bigger than str size");
		test_strncmp("a", "aa", 3, -97);
		test_strncmp("ab", "aaa", 4, 1);
		test_strncmp("aa", "a", 3, 97);
		test_strncmp("aaa", "ba", 4, -1);
	end_describe();
	describe("handles a as > A");
		test_strncmp("a", "A", 1, 32);
	end_describe();
	describe("handles n = 0 as always 0");
		test_strncmp("a", "A", 0, 0);
		test_strncmp("a", "a", 0, 0);
		test_strncmp("a", "aa", 0, 0);
	end_describe();
	describe("handles non pritable");
		it("handles \\200 and \\0");
		test_strncmp("test\200", "test\0", 6, 1);
	end_describe();
	return (test_status());
}
