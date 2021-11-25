/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_ft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:40:22 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/24 15:17:40 by mmelo-da         ###   ########lyon.fr   */
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
	char	*string;
	char	delimiter;
	char	**result;

	setup(argc, argv);
	describe("str split");
		 it("should return NULL if malloc fails");
			mock_malloc(1);
		 	string = "Hello,World";
		 	delimiter = ',';
		 	result = ft_split(string, delimiter);
		 	assert_equal_ptr(result, NULL, NULL);
		 	mock_malloc(0);
		 it("should return Hello and World");
			string = "Hello,World";
			delimiter = ',';
			result = (char **) ft_split(string, delimiter);
			assert_equal_str(*result, "Hello", "string 1");
			assert_equal_str(*(result + 1), "World", "string 2");
			assert_equal_ptr(*(result + 2), NULL, "Ending");
		it("should return Hello and World and Yeah");
			string = "Hello,World,Yeah";
			delimiter = ',';
			result = (char **) ft_split(string, delimiter);
			assert_equal_str(*(result), "Hello", "string 1");
			assert_equal_str(*(result + 1), "World", "string 2");
			assert_equal_str(*(result + 2), "Yeah", "string 3");
			assert_equal_ptr(*(result + 3), NULL, "string 1");
		it("should empty string if no word is present");
			string = "";
			delimiter = ',';
			result = (char **) ft_split(string, delimiter);
			assert_equal_ptr(*(result), NULL, "string 1");
		it("should return the single word if no delimiter is present");
			string = "Hello";
			delimiter = ',';
			result = (char **) ft_split(string, delimiter);
			assert_equal_str(*(result), "Hello", "string 1");
			assert_equal_ptr(*(result + 1), NULL, "string 1");
		it("should return empty string between consecutive delimiter");
			string = "Hello,,";
			delimiter = ',';
			result = (char **) ft_split(string, delimiter);
			assert_equal_str(*(result), "Hello", "string 1");
			assert_equal_ptr(*(result + 1), NULL, "string 4");
		it("should print empty line");
			string = "          ";
			delimiter = ' ';
			result = (char **) ft_split(string, delimiter);
			assert_equal_ptr(*(result), NULL, "string 2");
 	end_describe();
	return (test_status());
}
