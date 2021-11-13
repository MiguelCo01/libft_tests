/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21_ft_strlcat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:50:02 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/11 19:38:09 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"
#include "ctype.h"
#include "string.h"

void reset_dest(char *dest, int dest_len)
{
	memset(dest, 0, dest_len);
	memset(dest, 'r', 6);
}

int max(int a, int b)
{
	return ((a > b) * a + (a <= b) *b);
}
int	main(int argc, char **argv)
{

	char	*dest;
	char	*dest_sys;
	int		dest_len;

	setup(argc, argv);

	dest_len = 15;
	dest = (char *)malloc(sizeof(*dest) * dest_len);
	dest_sys = (char *)malloc(sizeof(*dest_sys) * dest_len);
	int str_size = 0;
	int str_size_sys = 0;

	describe("strlcat >> cat after first \0");
		it("should cat after firt \\0 even if non terminal NULL appears after");
			reset_dest(dest, dest_len);
			reset_dest(dest_sys, dest_len);
			dest[11] = 'a';
			dest_sys[11] = 'a';
			str_size = ft_strlcat(dest, "lorem", 15);
			str_size_sys = strlcat(dest_sys, "lorem", 15);
			assert_equal_memory(dest, dest_sys, max(strlen(dest_sys), 15), NULL);
			assert_equal_int(str_size, str_size_sys, NULL);
		it("should return the original if nothing is cat");
			reset_dest(dest, dest_len);
			reset_dest(dest_sys, dest_len);
			str_size = ft_strlcat(dest, "", 15);
			str_size_sys = strlcat(dest_sys, "", 15);
			assert_equal_memory(dest, dest_sys, max(strlen(dest_sys), 15), NULL);
			assert_equal_int(str_size, str_size_sys, NULL);
		it("should copy if first char is NULL TERMINATOR");
			reset_dest(dest, dest_len);
			reset_dest(dest_sys, dest_len);
			dest[0] = '\0';
			dest[11] = 'a';
			str_size = ft_strlcat(dest, "lorem ipsum", 15);
			dest_sys[0] = '\0';
			dest_sys[11] = 'a';
			str_size_sys = strlcat(dest_sys, "lorem ipsum", 15);
			assert_equal_memory(dest, dest_sys, max(strlen(dest_sys), 15), NULL);
			assert_equal_int(str_size, str_size_sys, NULL);
		it("should copy if first char is NULL TERMINATOR");
			reset_dest(dest, dest_len);
			reset_dest(dest_sys, dest_len);
			dest[14] = 'a';
			str_size = ft_strlcat(dest, "lorem ipsum dolor sit amet", 15);
			dest_sys[14] = 'a';
			str_size_sys = strlcat(dest_sys, "lorem ipsum dolor sit amet", 15);
			assert_equal_memory(dest, dest_sys, max(strlen(dest_sys), 15), NULL);
			assert_equal_int(str_size, str_size_sys, NULL);
		it("should concatenate until n");
			reset_dest(dest, dest_len);
			reset_dest(dest_sys, dest_len);
			dest[10] = 'a';
			str_size = ft_strlcat(dest, "lorem ipsum dolor sit amet", 0);
			dest_sys[10] = 'a';
			str_size_sys = strlcat(dest_sys, "lorem ipsum dolor sit amet", 0);
			assert_equal_memory(dest, dest_sys, max(strlen(dest_sys), 15), NULL);
			assert_equal_int(str_size, str_size_sys, NULL);
		it("should concat until 1");
			reset_dest(dest, dest_len);
			reset_dest(dest_sys, dest_len);
			dest[10] = 'a';
			str_size = ft_strlcat(dest, "lorem ipsum dolor sit amet", 1);
			dest_sys[10] = 'a';
			str_size_sys = strlcat(dest_sys, "lorem ipsum dolor sit amet", 1);
			assert_equal_memory(dest, dest_sys, max(strlen(dest_sys), 15), NULL);
			assert_equal_int(str_size, str_size_sys, NULL);
		it("should concat until 1");
			reset_dest(dest, dest_len);
			reset_dest(dest_sys, dest_len);
			memset(dest, 'r', 15);
			str_size = ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
			memset(dest_sys, 'r', 15);
			str_size_sys = strlcat(dest_sys, "lorem ipsum dolor sit amet", 5);
			assert_equal_memory(dest, dest_sys, max(strlen(dest_sys), 15), NULL);
			assert_equal_int(str_size, str_size_sys, NULL);
		it("should concat until 1");
			reset_dest(dest, dest_len);
			reset_dest(dest_sys, dest_len);
			dest[10] = 'a';
			str_size = ft_strlcat(dest, "lorem ipsum dolor sit amet", 6);
			dest_sys[10] = 'a';
			str_size_sys = strlcat(dest_sys, "lorem ipsum dolor sit amet", 6);
			assert_equal_memory(dest, dest_sys, max(strlen(dest_sys), 15), NULL);
			assert_equal_int(str_size, str_size_sys, NULL);
		it("should concat until 1");
			reset_dest(dest, dest_len);
			reset_dest(dest_sys, dest_len);
			memset(dest, 'r', 14);
			str_size = ft_strlcat(dest, "lorem ipsum dolor sit amet", 15);
			memset(dest_sys, 'r', 14);
			str_size_sys = strlcat(dest_sys, "lorem ipsum dolor sit amet", 15);
			assert_equal_memory(dest, dest_sys, max(strlen(dest_sys), 15), NULL);
			assert_equal_int(str_size, str_size_sys, NULL);
	end_describe();

	free(dest);
	return (test_status());
}
