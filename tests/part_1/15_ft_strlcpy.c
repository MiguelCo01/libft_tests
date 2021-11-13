/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_ft_strlcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:21:43 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/11 19:38:54 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"
#include <string.h>

#define BUFF_SIZE 11

int	main(int argc, char **argv)
{
	char *s;
	char buf[BUFF_SIZE];
	int len;
	setup(argc, argv);
	describe("takes the full size of the buffer not the str length");
		it("should copy the full string if buff_size is equal to length");
			s = "0123456789";
			bzero(buf, BUFF_SIZE);
			len = ft_strlcpy(buf, s, BUFF_SIZE);
			assert_equal_str(buf, s, NULL);
			assert_equal_int(len, 10, NULL);
		it("should copy partial string if size less than length");
			bzero(buf, BUFF_SIZE);
			memset(buf, 'r', 6);
			len = ft_strlcpy(buf, "lorem ipsum", 3);
			assert_equal_memory(buf, "lo\0rrr\0\0\0\0",BUFF_SIZE, NULL);
			assert_equal_int(len, 11, NULL);

			bzero(buf, BUFF_SIZE);
			memset(buf, 'r', 6);
			len = strlcpy(buf, "lorem ipsum", 3);
			assert_equal_memory(buf, "lo\0rrr\0\0\0\0",BUFF_SIZE, "SYS");
			assert_equal_int(len, 11, "SYS");

		it("should copy the full string if buff_size bigger to length");
			s = "012345";
			bzero(buf, BUFF_SIZE);
			len = ft_strlcpy(buf, s, BUFF_SIZE);
			assert_equal_str(buf, s, NULL);
			assert_equal_int(len, 6, NULL);

			bzero(buf, BUFF_SIZE);
			len = strlcpy(buf, s, BUFF_SIZE);
			assert_equal_str(buf, s, "SYS");
			assert_equal_int(len, 6, "SYS");

		it("should copy the size - 1 if buff_size smaller then length");
			s = "01234567890";
			bzero(buf, BUFF_SIZE);
			len = ft_strlcpy(buf, s, BUFF_SIZE);
			assert_equal_str(buf, "0123456789", NULL);
			assert_equal_int(len, 11, NULL);

			bzero(buf, BUFF_SIZE);
			len = strlcpy(buf, s, BUFF_SIZE);
			assert_equal_str(buf, "0123456789", "SYS");
			assert_equal_int(len, 11, "SYS");
	end_describe();
	describe("if size = 0 nothing happens");
		it("size = 0");
			s = "01234567890";
			bzero(buf, BUFF_SIZE);
			len = ft_strlcpy(buf, s, 0);
			assert_equal_str(buf, "\0", NULL);
			assert_equal_int(len, 11, NULL);

			bzero(buf, BUFF_SIZE);
			len = strlcpy(buf, s, 0);
			assert_equal_str(buf, "\0", "SYS");
			assert_equal_int(len, 11, "SYS");
	end_describe();
	return (test_status());
}
