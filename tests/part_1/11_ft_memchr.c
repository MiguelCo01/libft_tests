/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_ft_memchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:50:02 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/09 08:12:02 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"
#include "stdio.h"


int	main(int argc, char **argv)
{
	setup(argc, argv);

	describe("search for char c in the fist n bytes of s");
		char *s = "abc";
		it("finds c in abc");
			assert_equal_ptr(ft_memchr(s, 'c', 4), s + 2, NULL);
		it("finds a in abc");
			assert_equal_ptr(ft_memchr(s, 'a', 4), s, NULL);
	end_describe();
	describe("search for char c in the fist n bytes of s with null char");
		char *s2 = "a\0c";
		it("finds null char in a[null]c");
			assert_equal_ptr(ft_memchr(s2, '\0', 4), s2 + 1, NULL);
	end_describe();

	describe("return null if not found in s");
		it("return null if char not present");
			assert_equal_ptr(ft_memchr(s, 'z', 4), NULL, NULL);
		it("return null if search n does not include c");
			assert_equal_ptr(ft_memchr(s, 'c', 1), NULL, NULL);
	end_describe();

	describe("also works with intengers");
		it("can find intenger");
		int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
		assert_equal_ptr(ft_memchr(tab, -1, 7), (char *)tab + 1, NULL);
		assert_equal_ptr(ft_memchr(tab, -1, 7), memchr(tab, -1, 7), "Original");
		assert_equal_memory(ft_memchr(tab, -1, 7), (char *) tab + 1, 28, NULL);
		assert_equal_memory(ft_memchr(tab, -1, 7), memchr(tab, -1, 7), 28, "Original");
	end_describe();
	return (test_status());
}
