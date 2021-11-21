/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_ft_putnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:40:22 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/21 18:04:36 by mmelo-da         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	Outputs the integer ’n’ to the given filedescriptor.
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
	describe("ft_putnbr_fd");
		it("writes positive numbers");
			fd = create_tempfile("test-XX", "");
			memset(buffer, 0, sizeof(buffer));
			ft_putnbr_fd(10, fd);
			lseek(fd, 0, SEEK_SET);
			bytes = read(fd, buffer, 10);
			assert_equal_str(buffer, "10", NULL);
		it("writes positive numbers even if the fd has text");
			fd = create_tempfile("test-XX", "abc");
			memset(buffer, 0, sizeof(buffer));
			ft_putnbr_fd(10, fd);
			lseek(fd, 0, SEEK_SET);
			bytes = read(fd, buffer, 10);
			assert_equal_str(buffer, "abc10", NULL);
		it("writes negative numbers");
			fd = create_tempfile("test-XX", "");
			memset(buffer, 0, sizeof(buffer));
			ft_putnbr_fd(-10, fd);
			lseek(fd, 0, SEEK_SET);
			bytes = read(fd, buffer, 10);
			assert_equal_str(buffer, "-10", NULL);
		it("writes positive numbers even if the fd has text");
			fd = create_tempfile("test-XX", "abc");
			memset(buffer, 0, sizeof(buffer));
			ft_putnbr_fd(-10, fd);
			lseek(fd, 0, SEEK_SET);
			bytes = read(fd, buffer, 10);
			assert_equal_str(buffer, "abc-10", NULL);
		it("should do nothing if fd is invalid ( < 0 )");
			ft_putnbr_fd(0, -1);
	end_describe();
	return (test_status());
}
