/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_ft_putchar_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:40:22 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/21 17:48:42 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	Outputs the character ’c’ to the given filedescriptor.
*/


#include "core.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<errno.h>

int	create_tempfile(char *name, char *content)
{
	char	name_buffer[32];
	int		filedes;

	filedes = -1;
	memset(name_buffer, 0, sizeof(name_buffer));
	strncpy(name_buffer, name, 21);
	filedes = mkstemp(name_buffer);
	unlink(name_buffer);
	write(filedes, content, strlen(content));
	return (filedes);
}

int	main(int argc, char **argv)
{
	char	buffer[24];
	int		fd;
	int		bytes;

	setup(argc, argv);
	memset(buffer, 0, sizeof(buffer));
	strncpy(buffer, "", 24);
	describe("ft_putchar_fd");
		it("prints char c to fd");
			fd = create_tempfile("test-XX", "");
			ft_putchar_fd('a', fd);
			lseek(fd, 0, SEEK_SET);
			bytes = read(fd, buffer, 5);
			assert_equal_str(buffer, "a", NULL);
		it("should write char at end");
			fd = create_tempfile("test-XX", "abc");
			ft_putchar_fd('d', fd);
			lseek(fd, 0, SEEK_SET);
			bytes = read(fd, buffer, 5);
			assert_equal_str(buffer, "abcd", NULL);
		it("should do nothing if fd is invalid ( < 0 )");
			ft_putchar_fd('a', -1);
	end_describe();
	return (test_status());
}
