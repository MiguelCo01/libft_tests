/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18_ft_calloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:12:53 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/24 01:56:48 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
The calloc() function allocates memory for an array of nmemb elements of size  bytes
each  and returns a pointer to the allocated memory.  The memory is set to zero.  If
nmemb or size is 0, then calloc() returns either NULL, or  a  unique  pointer  value
that can later be successfully passed to free().  If the multiplication of nmemb and
size would result in integer overflow, then calloc() returns an error.  By contrast,
an  integer  overflow  would not be detected in the following call to malloc(), with
the result that an incorrectly sized block of memory would be allocated:

The  malloc() and calloc() functions return a pointer to the allocated memory, which
is suitably aligned for any built-in type.  On error, these functions  return  NULL.
NULL  may  also be returned by a successful call to malloc() with a size of zero, or
by a successful call to calloc() with nmemb or size equal to zero.

*/

#include "core.h"
#include "libft.h"
#include "utils.h"

int	main(int argc, char **argv)
{

	setup(argc, argv);
	describe("ft_calloc");
		it("returns a pointer to a memory space of  nmemb * sizeof element");
			char *expected = "\0\0\0\0\0\0\0\0\0\0";
			assert_equal_memory(ft_calloc(10, 1), expected, 10, NULL);
		it("returns NULL if nmemb is 0");
			assert_equal_ptr(ft_calloc(INT32_MAX, 2), NULL, NULL);
		it("works with empty strings?");
			int size = 8539;
			void * d1 = ft_calloc(size, sizeof(int));
			void * d2 = calloc(size, sizeof(int));
			assert_equal_memory(d1, d2, size * sizeof(int), NULL);
			free(d1);
			free(d2);
	end_describe();
	return (test_status());
}
