/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23_ft_strnstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:11:18 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/23 23:34:12 by mmelo-da         ###   ########lyon.fr   */
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
#include "string.h"

int	main(int argc, char **argv)
{

	setup(argc, argv);

	char *little;
	char *big;
	describe("STRNSTR");
		it("returns the first char of big where little is found");
			big = "o meu nome e miguel!";
			little = "nome";
			assert_equal_ptr(ft_strnstr(big, little, strlen(big)), strnstr(big, little, strlen(big)), NULL);
		it("returns the first char of big where little is found");
			big = "o meu \0nome e miguel!";
			little = "nome";
			assert_equal_ptr(ft_strnstr(big, little, strlen(big)), strnstr(big, little, strlen(big)), NULL);
		it("returns big if little is empty");
			big = "o meu nome e miguel!";
			little = "";
			assert_equal_ptr(ft_strnstr(big, little, strlen(big)), strnstr(big, little, strlen(big)), NULL);
		it("returns NULL if little not found");
			big = "o meu nome e miguel!";
			little = "zzz";
			assert_equal_ptr(ft_strnstr(big, little, strlen(big)), strnstr(big, little, strlen(big)), NULL);
		it("returns NULL if little not found as a whole until the n char");
			big = "lorem ipsum dolor sit amet";
			little = "dolor";
			assert_equal_ptr(ft_strnstr(big, little, 15), strnstr(big, little, 15), NULL);
		it("should return start if string is empty");
			big = (char*)"";
			little = "";		
			assert_equal_ptr(ft_strnstr(big, little, 0), strnstr(big, little, 0), NULL);
		it("should return empty if bug is empty and little has value");
			big = (char*)"";
			little = "coucou";		
			assert_equal_ptr(ft_strnstr(big, little, -1), strnstr(big, little, -1), NULL);
			assert_equal_ptr(ft_strnstr(big, little, -1), 0, NULL);
		it("it should return start of string if the little is exactly equal to the start until n chars");
			big = "aaabcabcd";
			little = "aaabc";
			assert_equal_ptr(ft_strnstr(big, little, 5), big, NULL);
	end_describe();

	return (test_status());
}

