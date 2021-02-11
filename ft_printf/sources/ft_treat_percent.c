/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:15:32 by eerika            #+#    #+#             */
/*   Updated: 2021/02/11 20:25:05 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_treat_percent(t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_putchar('%');
	char_count += ft_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		char_count += ft_putchar('%');
	return (char_count);
}
