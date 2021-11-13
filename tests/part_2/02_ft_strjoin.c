/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_ft_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:18:35 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/11 20:35:12 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
Description

Allocates (with malloc(3)) and returns a newstring, which is the result of the concatenationof ’s1’ and ’s2’.

*/

#include "core.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	setup(argc, argv);
	char *result;
	describe("strjoin");
		it("should return the concatenation of 'Hello' and ' World'");
			result = ft_strjoin("Hello", " World");
			assert_equal_str(result, "Hello World", NULL);
			free(result);
		it("should return the concatenation of 'Hello' and ''");
			result = ft_strjoin("Hello", "");
			assert_equal_str(result, "Hello", NULL);
			free(result);
		it("should return the concatenation of '' and ' World'");
			result = ft_strjoin("", " World");
			assert_equal_str(result, " World", NULL);
			free(result);
	end_describe();

	return (test_status());
}
