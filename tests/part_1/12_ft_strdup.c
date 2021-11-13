/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_ft_strdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:11:18 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/10 20:16:07 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description:
The strnstr() function locates the first occurrence of the null-terminated string
     little in the string big, where not more than len characters are searched.  Characters
     that appear after a ‘\0’ character are not searched.  Since the strnstr() function is
     a FreeBSD specific API, it should only be used when portability is not a concern.

Return Value
If little is an empty string, big is returned; if little occurs nowhere in big, NULL
     is returned; otherwise a pointer to the first character of the first occurrence of
     little is returned.
*/

#include "core.h"
#include "libft.h"
#include "utils.h"

int	main(int argc, char **argv)
{

	setup(argc, argv);

	todo("strdup");
	return (test_status());
}

