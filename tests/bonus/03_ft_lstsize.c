/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_ft_lstsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:21:29 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/25 00:56:41 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"

static void freeList(t_list *head) {if (head) freeList(head->next); free(head);}

int	main(int argc, char **argv)
{
	setup(argc, argv);
	t_list *lst;
	describe("ft_lstadd_front");
		it("returns the len of 1 if lst is only 1 item");
			lst = ft_lstnew("0");
			assert_equal_int(ft_lstsize(lst), 1, NULL);
			freeList(lst);
		it("returns the len of lst");
			t_list **lst_head = malloc(sizeof(t_list *));
			t_list *item1 = ft_lstnew("0");
			t_list *item2 = ft_lstnew("1");
			t_list *item3 = ft_lstnew("2");
			*lst_head = item3;
			ft_lstadd_front(lst_head, item2);
			ft_lstadd_front(lst_head, item1);
			assert_equal_int(ft_lstsize(item1), 3, "Item 1");
			assert_equal_int(ft_lstsize(item2), 2, "Item 2");
			assert_equal_int(ft_lstsize(item3), 1, "Item 3");
			freeList(*lst_head);
		it("returns 0 ptr if no list is given");
			assert_equal_int(ft_lstsize(0), 0, NULL);
	end_describe();
	return (test_status());
}