/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ft_substr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:49:30 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/11 20:17:19 by mmelo-da         ###   ########lyon.fr   */
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
	char *s;
	char *sub;
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
			assert_equal_ptr(sub, NULL, NULL);
			free(sub);
		it("if string = 'orem ipsum dolo' and start = 6 and len = 0");
			s = "lorem ipsum dolo";
			sub = ft_substr(s, 6, 0);
			assert_equal_str(sub, "", NULL);
			free(sub);
	end_describe();

	return (test_status());
}
