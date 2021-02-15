/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:24:04 by eerika            #+#    #+#             */
/*   Updated: 2021/02/15 13:29:55 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_str(char *str, int len)
{
	int count;

	count = 0;
	while (str[count] && count < len)
		ft_putchar(str[count++]);
	return (count);
}

int		print_width(int width, int eliminate, int zero_exist)
{
	int count;

	count = 0;
	while (width - eliminate > 0)
	{
		if (zero_exist)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		count += 1;
	}
	return (count);
}

int		ft_putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
