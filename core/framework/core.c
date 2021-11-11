/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:45:49 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/06 19:40:32 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#define MAX_ERROR_MSG_LEN 1024

char	*g_cur_suite = NULL;
char	*g_cur_it = NULL;
int		g_it_status = 1; // 1 - OK 0 - NOK
int		g_suite_status = 1; // 1 - OK 0 - NOK
int		g_mode = 0; // 0 - run 1 - run single 2 - no run
int		g_total_it = 0;
int		g_it_run = 0;

void	setup(int argc, char **argv)
{
	if (argc == 2 && strcmp(argv[1], "-no-run") == 0)
	{
		g_mode = 2;
		return ;
	}
	if (argc == 2 && atoi(argv[1]) > 0)
	{
		g_mode = 1;
		g_it_run = atoi(argv[1]);
		return ;
	}
}

void	describe(char *sutie_name)
{
	if (g_mode == 2)
		return;

	g_cur_suite = sutie_name;

}

void	end_describe()
{
	if (g_mode == 2)
		return;
	else if (g_mode == 0 || (g_mode == 1 && g_total_it == g_it_run))
	{
		if (g_it_status == 1)
		{
			write(1, "[SUITE] ", strlen("[SUITE] "));
			write(1, g_cur_suite, strlen(g_cur_suite));
			write(1, "\n", 1);
		}
	}
}
void todo(char *suite_name)
{
	describe(suite_name);
		it("No Tests...");
			assertion_fail("Not implemented yet!");
		end_it();
	end_describe();
}
void	it(char *test_name)
{

	if (g_cur_it != NULL)
		end_it();

	g_total_it++;
	g_cur_it = test_name;
	g_it_status = 1;
}

void	end_it(void)
{
	if (g_mode == 2)
		return ;
	else if (g_mode == 0 || (g_mode == 1 && g_total_it == g_it_run))
	{
		if (g_it_status == 1)
		{
			write(1, "[OK] ", 5);
			write(1, g_cur_it, strlen(g_cur_it));
			write(1, "\n", 1);
		}
	}
}

void	assertion_fail(char *error_msg, ...)
{
	va_list	valist;
	char	formated_error_msg[MAX_ERROR_MSG_LEN];

	if (g_mode == 2)
		return ;
	if (g_mode == 0 || (g_mode == 1 && g_total_it == g_it_run))
	{
		if (g_suite_status == 1)
		{
			printf("[SUITE NOK] >> %s\n", g_cur_suite);
			g_suite_status = 0;
		}

		if (g_it_status == 1)
		{
			printf("\t%d %s\n",  g_total_it, g_cur_it);
			g_it_status = 0;
		}

		va_start(valist, error_msg);
		vsprintf(formated_error_msg, error_msg, valist);
		printf("\t-- [NOK] %s\n", formated_error_msg);
		va_end(valist);
	}
}

void	assertion_pass(void)
{
	return ;
}

int		test_status(void)
{
	if (g_mode == 2)
		return (g_total_it);
	return (!g_suite_status);
}
