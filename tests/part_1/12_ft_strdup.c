/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_ft_strdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:11:18 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/24 15:43:18 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
Description:
The strnstr() function locates the first occurrence of the null-terminated string
     little in the string big, where not more than len characters are searched.  Characters
     that appear after a ‘\0’ character are not searched.  Since the strnstr() function is
     a FreeBSD specific API, it should only be used when portability is not a concern.

Return Value
If little is an empty string, big is returned; if little occurs nowhere in big, NULL
     is returned; otherwise a pointer to the first character of the first occurrence of
     little is returned.
*/

#include "core.h"
#include "libft.h"
#include "utils.h"

int	main(int argc, char **argv)
{
     char      *original;
     char      *dup;

	setup(argc, argv);
     describe("ft_strdup");
     it("should return an empty string if strdup on empty string");
          original = "";
          dup = ft_strdup((char*)"coucou");
          free(dup);
          dup = ft_strdup((char *)"");
          assert_equal_memory(dup, "", 1, NULL);
	return (test_status());
}
