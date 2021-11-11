/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:45:08 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/06 18:58:52 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "stdarg.h"
# include "stdio.h"
# define MAX_ERROR_MSG_LEN 1024


char	*formated_string(char *dst, char *string, ...);
char	*str_to_hex_str(char* output, char* input, size_t size);
#endif
