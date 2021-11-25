/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_ft_lstlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:21:29 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/25 01:10:58 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"

static void freeList(t_list *head) {if (head) freeList(head->next); free(head);}

int	main(int argc, char **argv)
{

	setup(argc, argv);
	describe("ft_lstlast");
	it("gets the last added item");
		t_list **lst = malloc(sizeof(t_list *));
		bzero(lst, sizeof(t_list *));
		t_list *item1 = ft_lstnew("1");
		t_list *item2 = ft_lstnew("2");
		t_list *item3 = ft_lstnew("3");
		ft_lstadd_front(lst, item3);
		ft_lstadd_front(lst, item2);
		ft_lstadd_front(lst, item1);
		assert_equal_ptr(ft_lstlast(*lst), item3, NULL);
		freeList(*lst);
		free(lst);
	it("gets the last added item even if only one element");
		t_list **lst2 = malloc(sizeof(t_list *));
		bzero(lst2, sizeof(t_list *));
		t_list *item21 = ft_lstnew("1");
		ft_lstadd_front(lst2, item21);
		assert_equal_ptr(ft_lstlast(*lst2), item21, NULL);
		freeList(*lst2);
		free(lst2);
	it("return null if no element in list");
		t_list **lst3 = malloc(sizeof(t_list *));
		bzero(lst3, sizeof(t_list *));
		assert_equal_ptr(ft_lstlast(*lst3), NULL, NULL);
		freeList(*lst3);
		free(lst3);
	end_describe();
	return (test_status());
}
