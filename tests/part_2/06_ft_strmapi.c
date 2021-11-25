/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_ft_strmapi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:40:22 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/24 00:27:03 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	Applies the function ’f’ to each character ofthe string ’s’ , and passing its index as firstargument to create a new string (with malloc(3))resulting from successive applications of ’f’.
*/


#include "core.h"
#include "libft.h"

char	mapper(unsigned	int i, char c)
{
	(void) i;
	return (c);
}

char	mapper_to_zero(unsigned	int i, char c)
{
	(void) i;
	(void) c;
	return ('0');
}

char	mapper_to_lower(unsigned	int i, char c)
{
	(void) i;
	return (ft_tolower(c));
}

char	mapper_to_index(unsigned	int i, char c)
{
	(void) c;
	return ((i % 10) + '0');
}

char addOne(unsigned int i, char c) {return (i + c);}


int	main(int argc, char **argv)
{
	char	*result;

	setup(argc, argv);
	describe("strmapi");
		it("it returns NULL if allocais fails");
			mock_malloc(1);
			result = ft_strmapi("Lorem ipsum dolor sit amet", mapper);
			assert_equal_ptr(result, NULL, NULL);
			mock_malloc(0);
		it("should apply the functino to every char");
			assert_equal_str(ft_strmapi("Lorem ipsum dolor sit amet", mapper_to_zero), "00000000000000000000000000", NULL);
		it("should make pass correct current char to f");
			assert_equal_str(ft_strmapi("Lorem iPsum Dolor sIt aMEt", mapper_to_lower), "lorem ipsum dolor sit amet", NULL);
		it("should make pass correct current index to f");
			assert_equal_str(ft_strmapi("Lorem iPsum Dolor sIt aMEt", mapper_to_index), "01234567890123456789012345", NULL);
		it("should make pass correct current index to f");
			char *s = ft_strmapi("1234", addOne);
			free(s);
			s = ft_strmapi("", addOne);
			assert_equal_str(s, "", NULL);
	end_describe();
	return (test_status());
}
