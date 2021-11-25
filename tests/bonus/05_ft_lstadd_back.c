/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_ft_lstadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:21:29 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/25 01:27:27 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"

//static void freeList(t_list *head) {if (head) freeList(head->next); free(head);}

#include "core.h"
#include "libft.h"
#include "utils.h"


static void freeList(t_list *head) {if (head) freeList(head->next); free(head);}
int	main(int argc, char **argv)
{

	setup(argc, argv);
	
	describe("ft_lstadd_back");
		it("adds new to end of head");
			t_list **lst = malloc(sizeof(t_list*));
			*lst = ft_lstnew("1");
			t_list *new = ft_lstnew("2");
			ft_lstadd_back(lst, new);
			assert_equal_str((*lst)->content, "1", NULL);
			assert_equal_str((*lst)->next->content, "2", NULL);
			freeList(*lst);
			free(lst);
		 it("should return new if even if lst is null");
		 	lst = malloc(sizeof(t_list*));
			*lst = NULL;
			new = ft_lstnew("2");
			ft_lstadd_back(lst, new);
			assert_equal_str((*lst)->content, "2", NULL);
			assert_equal_ptr((*lst)->next, NULL, NULL);
			freeList(*lst);
			free(lst);
		 it("should return lst if new is null");
			lst = malloc(sizeof(t_list*));
			*lst = ft_lstnew("1");
			new = NULL;
			ft_lstadd_front(lst, new);
			assert_equal_str((*lst)->content, "1", NULL);
			assert_equal_ptr((*lst)->next, NULL, NULL);
			freeList(*lst);
			free(lst);
		it("should NULL if both NULL");
			lst = malloc(sizeof(t_list*));
			*lst = NULL;
			new = NULL;
			ft_lstadd_front(lst, new);
			assert_equal_ptr(*lst, NULL, NULL);
			freeList(*lst); 
			free(lst);
		it("add multiple to the end");
			lst = malloc(sizeof(t_list*));
			*lst = ft_lstnew("1");
			new = ft_lstnew("2");
			t_list *new2 = ft_lstnew("3");
			ft_lstadd_back(lst, new);
			ft_lstadd_back(lst, new2);
			assert_equal_str((*lst)->content, "1", NULL);
			assert_equal_str((*lst)->next->content, "2", NULL);
			assert_equal_str((*lst)->next->next->content, "3", NULL);
			freeList(*lst);
			free(lst);
	end_describe();
	return (test_status());
}