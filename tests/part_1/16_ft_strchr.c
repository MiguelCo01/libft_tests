/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_ft_strchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:21:43 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/24 17:40:39 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	char *s = "abcde\tfghijklmnopqrstuvwxyz";

	setup(argc, argv);
	describe("returns first occurence of c in s");
		it("if string is not empty and char is found");
			assert_equal_ptr(ft_strchr(s, 'c'), s + 2, NULL);
		it("works with non pritable");
			assert_equal_ptr(ft_strchr(s, '\t'), s + 5, NULL);
	end_describe();
	describe("returns NULL if not found");
		it("if string is empty");
			assert_equal_ptr(ft_strchr("", 'a'), NULL, NULL);
		it("if string is not empty but char is not found");
			assert_equal_ptr(ft_strchr(s, '9'), NULL, NULL);
	end_describe();
	return (test_status());
}
