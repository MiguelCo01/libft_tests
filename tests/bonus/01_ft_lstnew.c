/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ft_lstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:50:02 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/24 19:09:53 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"

int	main(int argc, char **argv)
{

	setup(argc, argv);
	t_list *result;
	describe("ft_lstnew");
		it("creates a new list struct if content is null");
			result = ft_lstnew(0);
			assert_equal_ptr(result->content, NULL, NULL);
			assert_equal_ptr(result->next, NULL, NULL);
			free(result);
		it("creates a new list struct if content is string");
			result = ft_lstnew("hello");
			assert_equal_str(result->content, "hello", NULL);
			assert_equal_ptr(result->next, NULL, NULL);
			free(result);
		it("creates a new list struct if content is ptr to int");
			int i;
			i = 1;
			result = ft_lstnew(&i);
			assert_equal_int(*((int *) result->content), 1, NULL);
			assert_equal_ptr((int *) result->content, &i , NULL);
			assert_equal_ptr(result->next, NULL, NULL);
			free(result);
		it("return null if malloc cannot allocate");
			mock_malloc(1);
			result = ft_lstnew(0);
			assert_equal_ptr(result, NULL, NULL);
			mock_malloc(0);
	end_describe();
	return (test_status());
}
