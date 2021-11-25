/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_ft_lstadd_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:50:02 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/25 00:12:37 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"


static void freeList(t_list *head) {if (head) freeList(head->next); free(head);}
int	main(int argc, char **argv)
{

	setup(argc, argv);
	
	describe("ft_lstadd_front");
		it("adds new to begginig of head");
			t_list **lst = malloc(sizeof(t_list*));
			*lst = ft_lstnew("1");
			t_list *new = ft_lstnew("2");
			ft_lstadd_front(lst, new);
			assert_equal_str((*lst)->content, "2", NULL);
			assert_equal_str((*lst)->next->content, "1", NULL);
			freeList(*lst);
		it("should return new if even if lst is null");
			*lst = NULL;
			new = ft_lstnew("2");
			ft_lstadd_front(lst, new);
			assert_equal_str((*lst)->content, "2", NULL);
			assert_equal_ptr((*lst)->next, NULL, NULL);
			freeList(*lst);
		it("should return lst if new is null");
			*lst = ft_lstnew("1");
			new = NULL;
			ft_lstadd_front(lst, new);
			assert_equal_str((*lst)->content, "1", NULL);
			assert_equal_ptr((*lst)->next, NULL, NULL);
			freeList(*lst);
		it("should NULL if both NULL");
			*lst = NULL;
			new = NULL;
			ft_lstadd_front(lst, new);
			assert_equal_ptr(*lst, NULL, NULL);
			freeList(*lst);
	end_describe();
	return (test_status());
}
