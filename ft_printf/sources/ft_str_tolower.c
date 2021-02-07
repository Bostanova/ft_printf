/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:33:50 by eerika            #+#    #+#             */
/*   Updated: 2021/02/07 18:01:36 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char    *ft_str_tolower(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        str[i] = ft_tolower(str[i]);
    return (str);
}