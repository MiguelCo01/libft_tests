/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19_ft_bzero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:50:02 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/10 10:01:37 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"
#include "ctype.h"

int	main(int argc, char **argv)
{

	setup(argc, argv);

	describe("Bzero");
		char *s1 = malloc(5);
		it("changes n bytes to 0");
			memset(s1, 'c', 5);
			ft_bzero(s1, 5);
			assert_equal_memory(s1, "\0\0\0\0\0", 5, NULL);
		it("changes 0 bytes to 0");
			memset(s1, 'c', 5);
			ft_bzero(s1, 0);
			assert_equal_memory(s1, "ccccc", 5, NULL);
			free(s1);
	end_describe();

	return (test_status());
}
