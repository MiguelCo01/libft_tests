/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_ft_strlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:54:24 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/08 09:57:04 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	setup(argc, argv);

	describe("retusn the string length");
		it("return 0 if empty string");
			assert_equal_int(ft_strlen(""), 0, NULL);

		it("return 1 if string with 1 char");
			assert_equal_int(ft_strlen("c"), 1, NULL);
			assert_equal_int(ft_strlen("d"), 1, NULL);

		it("return n if string with n char");
			assert_equal_int(ft_strlen("aaaaa"), 5, NULL);
			assert_equal_int(ft_strlen("aaaaaaaaaa"), 10, NULL);

		it("handles space has normal char");
			assert_equal_int(ft_strlen("\n\n\f\r\t"), 5, NULL);
	end_describe();
	return (test_status());
}
