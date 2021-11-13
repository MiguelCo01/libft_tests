/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_ft_strtrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:18:35 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/13 15:59:55 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
Description

*/

#include "core.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	char	*string;
	char	*set;
	char 	*result;
	setup(argc, argv);
	describe("strtrim");
		it("Trim form beggining with set='a'");
			string = "aHello";
			set = "a";
			result = ft_strtrim(string, set);
			assert_equal_str(result, "Hello", NULL);
			free(result);
		it("Trim form beggining with set='abc'");
			string = "abbbbccccHello";
			set = "abc";
			result = ft_strtrim(string, set);
			assert_equal_str(result, "Hello", NULL);
			free(result);
		it("Trim form end with set='abc'");
			string = "Helloaabbcc";
			set = "abc";
			result = ft_strtrim(string, set);
			assert_equal_str(result, "Hello", NULL);
			free(result);
		it("Trim string with only set chars, with set='abc', expect empty string");
			string = "abccba";
			set = "abc";
			result = ft_strtrim(string, set);
			assert_equal_str(result, "", NULL);
			free(result);
		it("Does not elimante set char in middle of string");
			string = "abHelloc WorldcbYeaha";
			set = "abc";
			result = ft_strtrim(string, set);
			assert_equal_str(result, "Helloc WorldcbYeah", NULL);
			free(result);
		it("Malloc Fails");
			string = "abHelloc WorldcbYeaha";
			set = "abc";
			mock_malloc(1);
			result = ft_strtrim(string, set);
			assert_equal_ptr(result, NULL, NULL);
			mock_malloc(0);
	end_describe();
	return (test_status());
}
