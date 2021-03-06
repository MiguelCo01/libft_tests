/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:08:10 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/23 21:46:32 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "utils.h"

void	assert_equal_int(int actual, int expected, char *error_msg)
{
	if (actual != expected)
	{
		assertion_fail("Recieved %d but Expected %d, %s\n",
			actual, expected, error_msg);
	}
	else
	{
		assertion_pass();
	}
}

void	assert_not_equal_int(int actual, int expected, char *error_msg)
{
	if (actual == expected)
	{
		assertion_fail("Expected %d to not equal %d, %s\n",
			actual, expected, error_msg);
	}
	else
	{
		assertion_pass();
	}
}

void	assert_equal_char(char actual, char expected, char *error_msg)
{
	if (actual != expected)
	{
		assertion_fail("Recieved '%c' but Expected '%c', %s",
			actual, expected, error_msg);
	}
	else
	{
		assertion_pass();
	}
}

void	assert_equal_ptr(void *actual, void *expected, char *error_msg)
{
	if (actual != expected)
	{
		assertion_fail("Recieved '%p' but Expected '%p', %s",
			actual, expected, error_msg);
	}
	else
	{
		assertion_pass();
	}
}

void	assert_equal_str(char *actual, char *expected, char *error_msg)
{
	if (actual == NULL)
	{
		assertion_fail("Actual is (Nil) - %s", error_msg);
		return ;
	}
	if (expected == NULL)
	{
		assertion_fail("Expected is (Nil) - %s", error_msg);
		return ;
	}
	if (!!strcmp(actual, expected))
	{
		assertion_fail("Recieved '%s' but Expected '%s', %s",
			actual, expected, error_msg);
	}
	else
	{
		assertion_pass();
	}
}

void	assert_not_equal_str(char *actual, char *expected, char *error_msg)
{
	if (actual == NULL)
	{
		assertion_fail("Actual is (Nil) - %s", error_msg);
		return ;
	}
	if (expected == NULL)
	{
		assertion_fail("Expected is (Nil) - %s", error_msg);
		return ;
	}
	if (!strcmp(actual, expected))
	{
		assertion_fail("Recieved '%s' but Expected '%s', %s",
			actual, expected, error_msg);
	}
	else
	{
		assertion_pass();
	}
}

void	assert_equal_memory(void *actual, void *expected, size_t size, char *error_msg)
{
	char *actual_hex_str;
	char *expected_hex_str;


	if (!!memcmp(actual, expected, size))
	{
		actual_hex_str = malloc(size * 2 * sizeof(actual));
		expected_hex_str = malloc(size * 2 * sizeof(expected));
		str_to_hex_str(actual_hex_str, actual, size);
		str_to_hex_str(expected_hex_str, expected, size);

		assertion_fail("Recieved '%s' \n\t     but Expected '%s', %s",
			actual_hex_str, expected_hex_str, error_msg);

		free(actual_hex_str);
		free(expected_hex_str);
	}
	else
	{
		assertion_pass();
	}
}

void	assert_not_equal_memory(void *actual, void *expected, size_t size, char *error_msg)
{
	char *actual_hex_str;
	char *expected_hex_str;


	if (!memcmp(actual, expected, size))
	{
		actual_hex_str = malloc(size * 2 * sizeof(actual));
		expected_hex_str = malloc(size * 2 * sizeof(expected));
		str_to_hex_str(actual_hex_str, actual, size);
		str_to_hex_str(expected_hex_str, expected, size);

		assertion_fail("Recieved '%s' \n\t     but Expected '%s', %s",
			actual_hex_str, expected_hex_str, error_msg);

		free(actual_hex_str);
		free(expected_hex_str);
	}
	else
	{
		assertion_pass();
	}
}
