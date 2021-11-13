/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21_ft_strrchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:52:30 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/10 20:08:40 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"

/*
Description
The strrchr() function returns a pointer to the last occurrence of the  character
c in the string s.

Return Value
The  strchr()  and  strrchr() functions return a pointer to the matched character or
NULL if the character is not found.  The terminating null byte is considered part of
the  string,  so that if c is specified as '\0', these functions return a pointer to
the terminator.
*/
int	main(int argc, char **argv)
{

	setup(argc, argv);

	char *s;
	describe("STRRCHR");
		it("if no char is found");
			s = "";
			assert_equal_ptr(ft_strrchr(s, 'a'), NULL, NULL);
		it("if no char is found");
			s = "abcd";
			assert_equal_ptr(ft_strrchr(s, '1'), NULL, NULL);
		it("if s = abcd and c = b");
			s = "abcd";
			assert_equal_ptr(ft_strrchr(s, 'b'), s + 1, NULL);
		it("s = abcd and c = NULL");
			s = "abcd";
			assert_equal_ptr(ft_strrchr(s, '\0'), s + 4, NULL);
		it("s = abcda and c = a");
			s = "abcda";
			assert_equal_ptr(ft_strrchr(s, 'a'), s + 4, NULL);
	end_describe();

	return (test_status());
}
