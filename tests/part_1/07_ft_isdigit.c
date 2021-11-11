/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_ft_isdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:28:49 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/08 09:53:19 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"

void	test_isdigit(char c, int expected)
{
	char formated_error[MAX_ERROR_MSG_LEN];

	it(formated_string(formated_error, "When c is %c", c));
		assert_equal_int(ft_isdigit(c), expected, NULL);
}

int	main(int argc, char **argv)
{
	setup(argc, argv);

	describe("returns 1 if digit");
		test_isdigit('0', 1);
		test_isdigit('1', 1);
		test_isdigit('9', 1);
	end_describe();

	describe("returns 0 if not digit");
		test_isdigit('a', 0);
		test_isdigit(' ', 0);
		test_isdigit('<', 0);
		test_isdigit('\xfc', 0);
		test_isdigit('\x00', 0);
	end_describe();

	return (test_status());
}
