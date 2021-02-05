/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrprec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:24:04 by eerika            #+#    #+#             */
/*   Updated: 2021/01/29 11:24:07 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int     ft_putstrprec(char *str, int prec)
{
    int char_count;

    char_count = 0;
    while (str[char_count] && char_count < prec)
        ft_putchar(str[char_count++]);
    return (char_count);
}