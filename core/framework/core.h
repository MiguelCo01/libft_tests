/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:47:39 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/24 20:17:23 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H
# include "stdio.h"
# include "stdarg.h"
# include "stdint.h"
# include "string.h"
# include "unistd.h"
# include "ctype.h"
# include "stdlib.h"

enum e_run_mode {normal_run, debug_run};
enum e_it_status {it_fail, it_pass, it_not_started};

void	assert_equal_int(int actual, int expected, char *error_msg);
void	assert_not_equal_int(int actual, int expected, char *error_msg);
void	assert_equal_char(char actual, char expected, char *error_msg);
void	assert_equal_ptr(void *actual, void *expected, char *error_msg);
void	assert_equal_str(char *actual, char *expected, char *error_msg);
void	assert_not_equal_str(char *actual, char *expected, char *error_msg);
void	assert_equal_memory(void *actual, void *expected, size_t size, char *error_msg);
void	assert_not_equal_memory(void *actual, void *expected, size_t size, char *error_msg);

void	setup(int argc, char **argv);

void	describe(char *suite_name);
void	end_describe(void);

void	it(char *test_name);
void	end_it(void);

void	assertion_fail(char *error_msg, ...);
void	assertion_pass(void);

int		test_status(void);
void	todo(char *suite_name);

void	mock_malloc(int mode);
#endif
