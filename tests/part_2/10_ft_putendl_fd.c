/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_ft_putendl_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:40:22 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/21 17:57:44 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	Outputs the string ’s’ to the given filedescriptor, followed by a newline.
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
	describe("ft_putendl_fd");
		it("prints char c to fd");
			fd = create_tempfile("test-XX", "");
			ft_putendl_fd("abc", fd);
			lseek(fd, 0, SEEK_SET);
			bytes = read(fd, buffer, 5);
			assert_equal_str(buffer, "abc\n", NULL);
		it("should write char at end");
			fd = create_tempfile("test-XX", "ab");
			ft_putendl_fd("cd", fd);
			lseek(fd, 0, SEEK_SET);
			bytes = read(fd, buffer, 5);
			assert_equal_str(buffer, "abcd\n", NULL);
		it("should write new line for every call");
			fd = create_tempfile("test-XX", "ab");
			ft_putendl_fd("c", fd);
			ft_putendl_fd("d", fd);
			lseek(fd, 0, SEEK_SET);
			bytes = read(fd, buffer, 10);
			assert_equal_str(buffer, "abc\nd\n", NULL);
		it("should do nothing if fd is invalid ( < 0 )");
			ft_putendl_fd("a", -1);
	end_describe();
	return (test_status());
}
