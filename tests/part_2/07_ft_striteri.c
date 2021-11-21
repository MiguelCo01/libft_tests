/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_ft_striteri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:40:22 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/21 17:00:52 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	Applies the function f to each character of thestring passed as argument, and passing its indexas first argument.  Each character is passed byaddress to f to be modified if necessary
*/


#include "core.h"
#include "libft.h"

char	mapper(unsigned	int i, char c)
{
	(void) i;
	return (c);
}

void	mapper_to_zero(unsigned	int i, char *c)
{
	(void) i;
	*c = '0';
}

void	mapper_to_lower(unsigned	int i, char *c)
{
	(void) i;
	*c = ft_tolower(*c);
}

void	mapper_to_index(unsigned	int i, char *c)
{
	*c = ((i % 10) + '0');
}



int	main(int argc, char **argv)
{
	char	*original;
	char	*string;

	setup(argc, argv);

	original = "Lorem ipsum dolor sit amet";

	describe("striter");
		it("should apply the functino to every char");
			string = strdup(original);
			ft_striteri(string, mapper_to_zero);
			assert_equal_str(string, "00000000000000000000000000", NULL);
			free(string);
		it("should make pass correct current char to f");
			string = strdup(original);
			ft_striteri(string, mapper_to_lower);
			assert_equal_str(string, "lorem ipsum dolor sit amet", NULL);
			free(string);
		it("should make pass correct current index to f");
			string = strdup(original);
			ft_striteri(string, mapper_to_index);
			assert_equal_str(string, "01234567890123456789012345", NULL);
			free(string);
	end_describe();
	return (test_status());
}
