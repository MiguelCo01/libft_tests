/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ft_substr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:49:30 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/24 00:22:40 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"

/*
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
*/
int	main(int argc, char **argv)
{
	char	*s;
	char	*sub;

	setup(argc, argv);
	describe("substr");
		it("if string = 'o meu nome e miguel' and start = 0 and len = 5");
			s = "lorem ipsum dolo";
			sub = ft_substr(s, 0, 5);
			assert_equal_str(sub, "lorem", NULL);
			free(sub);
		it("if string = 'o meu nome e miguel' and start = 0 and len = 5");
			s = "lorem ipsum dolo";
			sub = ft_substr(s, 6, 5);
			assert_equal_str(sub, "ipsum", NULL);
			free(sub);
		it("if string = '' and start = 6 and len = 5");
			s = "";
			sub = ft_substr(s, 6, 5);
			assert_equal_str(sub, "", NULL);
			free(sub);
		it("if string = 'orem ipsum dolo' and start = 6 and len = 0");
			s = "lorem ipsum dolo";
			sub = ft_substr(s, 6, 0);
			assert_equal_str(sub, "", NULL);
			free(sub);
		it("if malloc fails return NULL");
			s = "lorem ipsum dolo";
			mock_malloc(1);
			sub = ft_substr(s, 6, 0);
			assert_equal_ptr(sub, NULL, NULL);
			mock_malloc(0);
		it("should return empty string");
			s = "tripouille";
			sub = ft_substr(s, 100, 1);
			assert_equal_str(sub, "", NULL);
	end_describe();

	return (test_status());
}
