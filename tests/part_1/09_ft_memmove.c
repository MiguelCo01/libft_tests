/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_ft_memmove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:57:38 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/08 11:25:12 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"

int	main(int argc, char ** argv)
{
	char	*src;
	char	*dest;

	setup(argc, argv);

	describe("copies from src to dest - no overlap");
		it("moves simple strings");
			src  = strdup("lorem ipsum dolor sit amet");
			dest = src + 1;
			assert_equal_memory((char *) ft_memmove(dest, "consectetur", 5), "conseipsum dolor sit a", 22, NULL);
			free(src);
		it("moves string with '\\0' character in the middle");
			src  = strdup("lorem ipsum dolor sit amet");
			dest = src + 1;
			assert_equal_memory((char *) ft_memmove(dest, "con\0sec\0\0te\0tur", 10), "con\0sec\0\0t dolor sit a", 22, NULL);
			free(src);
	end_describe();

	describe("copies from src to dest - overlap");
		it("If dest starts after src");
			src  = strdup("lorem ipsum dolor sit amet");
			dest = src + 1;
			assert_equal_memory((char *) ft_memmove(dest, src, 8), "lorem ipum dolor sit a", 22, NULL);
			free(src);
		it("If dest starts before src");
			src  = strdup("lorem ipsum dolor sit amet");
			dest = src + 1;
			assert_equal_memory((char *) ft_memmove(src, dest, 8), "orem ipssum dolor sit ", 22, NULL);
			free(src);
	end_describe();

	describe("handles n = 0");
		it("makes no changes to the strings");
			src  = strdup("lorem ipsum dolor sit amet");
			dest = src + 1;
			assert_equal_memory((char *) ft_memmove(src, dest, 0), "lorem ipsum dolor sit ", 22, NULL);
			free(src);
	end_describe();
	describe("returns dest");
		it("makes no changes to the strings");
			src  = strdup("lorem ipsum dolor sit amet");
			dest = src + 1;
			assert_equal_ptr(dest, ft_memmove(dest, src, 0), NULL);
			free(src);
	end_describe();
	return (test_status());
}
