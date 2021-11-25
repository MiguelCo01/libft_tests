/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_ft_memcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:50:02 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/24 18:24:07 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include "utils.h"

void test_memcpy(size_t n)
{
	char test_name[MAX_ERROR_MSG_LEN];

	it(formated_string(test_name, "when copying %d bytes from str to str", n));
	void *src;
	void *dest;
	void *dest_expected;

	src = "abcdefghijklmnopqrstuwvxyz";
	dest = malloc(50);
	dest_expected = malloc(30);
	bzero(dest, 30);
	bzero(dest_expected, 30);

	ft_memcpy(dest, src, n);
	memcpy(dest_expected, src, n);
	assert_equal_memory(dest, dest_expected, 30, NULL);

	free(dest);
	free(dest_expected);
}

void test_memcpy_return_value(size_t n)
{
	char test_name[MAX_ERROR_MSG_LEN];

	it(formated_string(test_name, "when copying %d bytes from int memory space to int memory space", n));
	int src[5] = {1, 1020, 3, 4, 5};
	void *dest;

	dest = malloc(5 * sizeof(int));
	bzero(dest, 5 * sizeof(int));

	assert_equal_ptr(dest, ft_memcpy(dest, src, n), NULL);

	free(dest);
}

void test_memcpy_int(size_t n)
{
	char test_name[MAX_ERROR_MSG_LEN];

	it(formated_string(test_name, "when copying %d bytes from int memory space to int memory space", n));
	int src[5] = {1, 1020, 3, 4, 5};
	void *dest;
	void *dest_expected;

	dest = malloc(5 * sizeof(int));
	dest_expected = malloc(5 * sizeof(int));
	bzero(dest, 5 * sizeof(int));
	bzero(dest_expected, 5 * sizeof(int));

	ft_memcpy(dest, src, n);
	memcpy(dest_expected, src, n);
	assert_equal_memory(dest, dest_expected, 5 * sizeof(int), NULL);

	free(dest);
	free(dest_expected);
}


int	main(int argc, char **argv)
{
	setup(argc, argv);

	describe("copies n bytes from memeory string src to memoty string dest");
		test_memcpy(0);
		test_memcpy(1);
		test_memcpy(10);
	end_describe();

	describe("copies n bytes from memeory int arr src to int arr dest");
		test_memcpy_int(0);
		test_memcpy_int(1);
		test_memcpy_int(10);
	end_describe();

	describe("returns pointer to dest");
		test_memcpy_return_value(0);
		test_memcpy_return_value(1);
		test_memcpy_return_value(10);
	end_describe();

	describe("When both params are null");
	it("should not error");
		ft_memcpy(0, 0, 10);
		memcpy(0, 0, 10);
	end_describe();
	return (test_status());
}
