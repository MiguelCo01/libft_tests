/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18_ft_isascci.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:50:02 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/10 09:54:47 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"
#include "ctype.h"

void test_isalpha(int c, int expected)
{
	char test_name[MAX_ERROR_MSG_LEN];

	it(formated_string(test_name, "when char is %c", (unsigned char) c));
	assert_equal_int(!!ft_isascii(c), expected, NULL);
	it(formated_string(test_name, "when char is %c and comparint with original", (unsigned char) (c + 256)));
	assert_equal_int(!!ft_isascii((c)), !!isascii((c)), NULL);
}

int	main(int argc, char **argv)
{

	setup(argc, argv);

	describe("should return 1 if ascii");
		test_isalpha(0, 1);
		test_isalpha(50, 1);
		test_isalpha(127, 1);
	end_describe();

	describe("should return 0 if not ascii");
		test_isalpha(-1, 0);
		test_isalpha(128, 0);
	end_describe();

	return (test_status());
}
