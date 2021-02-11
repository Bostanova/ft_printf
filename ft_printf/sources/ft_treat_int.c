/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:09:55 by eerika            #+#    #+#             */
/*   Updated: 2021/02/11 20:22:24 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	auxiliary(char *str_of_ints, int i, t_flags flags)
{
	int count;

	count = 0;
	if (i < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		count += ft_width(flags.dot - 1, ft_strlen(str_of_ints) - 1, 1);
	count += ft_putstrprec(str_of_ints, ft_strlen(str_of_ints));
	return (count);
}

int			ft_treat_int(int i, t_flags flags)
{
	char	*str_of_ints;
	int		count;

	count = 0;
	if (flags.dot == 0 && i == 0)
	{
		ft_putchar('0');
		return (count++);
	}
	str_of_ints = ft_itoa(i);
	if (flags.minus == 1)
		count += auxiliary(str_of_ints, i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str_of_ints))
		flags.dot = ft_strlen(str_of_ints);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_width(flags.width, 0, 0);
	}
	else
		count += ft_width(flags.width, ft_strlen(str_of_ints), flags.zero);
	if (flags.minus == 0)
		count += auxiliary(str_of_ints, i, flags);
	free(str_of_ints);
	return (count);
}
