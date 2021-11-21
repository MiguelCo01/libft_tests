/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_ft_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:40:22 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/21 16:21:11 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The array of new strings resulting from the split.NULL if the allocation fails.

	Allocates (with malloc(3)) and returns an arrayof strings obtained by splitting ’s’ using thecharacter ’c’ as a delimiter.
	The array must beended by a NULL pointer.
*/


#include "core.h"
#include "libft.h"

int	main(int argc, char **argv)
{

	setup(argc, argv);
	describe("itoa");
		it("it returns NULL if allocais fails");
			mock_malloc(1);
			char *result = ft_itoa(0);
			assert_equal_ptr(result, NULL, NULL);
			mock_malloc(0);
		it("handles positive numbers");
			assert_equal_str(ft_itoa(0), "0", NULL);
			assert_equal_str(ft_itoa(1), "1", NULL);
			assert_equal_str(ft_itoa(2147483647), "2147483647", NULL);
		it("handles negative numbers");
			assert_equal_str(ft_itoa(-0), "0", NULL);
			assert_equal_str(ft_itoa(-1), "-1", NULL);
			assert_equal_str(ft_itoa(-2147483648), "-2147483648", NULL);
	end_describe();
	return (test_status());
}
