/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:57:47 by eerika            #+#    #+#             */
/*   Updated: 2021/02/07 18:02:19 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_treat_width(int width, int minus, int has_zero)
{
    int char_count;

    char_count = 0;
    while (width - minus > 0)
    {
        if (has_zero)
            ft_putchar('0');
        else
            ft_putchar(' ');
        width -= 1;
        char_count++;
    }
    return (char_count);
}
