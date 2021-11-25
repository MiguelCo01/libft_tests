/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_ft_split_unit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:40:22 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/24 14:29:09 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	The array of new strings resulting from the split.NULL if the allocation fails.

	Allocates (with malloc(3)) and returns an arrayof strings obtained by splitting ’s’ using thecharacter ’c’ as a delimiter.
	The array must beended by a NULL pointer.
*/

#include "core.h"
#include "libft.h"
#include "utils.h"

int	ft_count_words(char const *s, char c);

void    test_word_counter(char *s, char c, int expected)
{
    char error_msg[255];
    
    it(formated_string(error_msg, "returns one if s='%s' and delimiter='%c' should return wc of '%d", s, c, expected));
        assert_equal_int(ft_count_words(s, c), expected, NULL);
}


int	main(int argc, char **argv)
{
	setup(argc, argv);
	describe("ft_split word count");
        test_word_counter("lorem ipsum",'z', 1);
        test_word_counter("lorem-ipsum",'-', 2);
        test_word_counter("lorem--ipsum",'-', 2);
        test_word_counter("",'-', 0);
        test_word_counter("----a---a---a---a---",'-', 4);
	end_describe();
	return (test_status());
}
