/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:21:39 by eerika            #+#    #+#             */
/*   Updated: 2021/02/11 20:21:48 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_width(int width, int minus, int zero)
{
	int char_count;

	char_count = 0;
	while (width - minus > 0)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
		char_count++;
	}
	return (char_count);
}
