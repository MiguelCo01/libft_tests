/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_ft_memset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:11:47 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/09 08:21:02 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"
#include "stdio.h"


int	main(int argc, char **argv)
{
	setup(argc, argv);
	char *original = "abcdefghijklmnopqrstuvwxyz";
	char *s;
	char *s2;
	describe("sets n bytes of s as c");

		it("if n = 0, no bytes are changed");
			s = strdup(original);
			assert_equal_str(ft_memset(s, 'a', 0), original, NULL);
			free(s);
		it("if n > 0 and less than s size, no bytes are changed");
			s = strdup(original);
			assert_equal_str(ft_memset(s, 'a', 5), "aaaaafghijklmnopqrstuvwxyz", NULL);
			free(s);
		it("should work with non printable chars");
			s = strdup(original);
			assert_equal_str(ft_memset(s, '\n', 5), "\n\n\n\n\nfghijklmnopqrstuvwxyz", NULL);
			free(s);
		it("should work with non printable chars");
			s = strdup(original);
			assert_equal_str(ft_memset(s, '\0', 5), "\0\0\0\0\0nfghijklmnopqrstuvwxyz", NULL);
			free(s);
		it("should work with non printable chars");
			s = strdup("abc");
			s2 = strdup("abc");
			assert_equal_str(ft_memset(s, 'z',4), "zzzz", NULL);
			assert_equal_str(ft_memset(s, 'z',4), memset(s2, 'z',4), NULL);
			free(s2);
			free(s);
	end_describe();
	return (test_status());
}
