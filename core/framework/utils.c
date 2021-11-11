/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:45:36 by mmelo-da          #+#    #+#             */
/*   Updated: 2021/11/06 18:59:47 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char *formated_string(char *dst, char *string, ...)
{
	va_list	valist;
	va_start(valist, string);
	vsprintf(dst, string, valist);
	va_end(valist);
	return (dst);
}

char *str_to_hex_str(char* output, char* input, size_t size)
{
    int loop;
    int i;

    i=0;
    loop=0;

    while((size_t) loop < size)
    {
        sprintf((char*)(output+i),"%02X", input[loop]);
        loop+=1;
        i+=2;
    }
    //insert NULL at the end of the output string
    output[i++] = '\0';
	return (output);
}
