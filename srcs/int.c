/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:56:01 by eerika            #+#    #+#             */
/*   Updated: 2021/02/15 20:15:49 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dotflag_handling(char *str_from_int, int save_i, t_flags flags)
{
	int count;

	count = 0;
	if (save_i < 0 && flags.dot >= 0 )
		ft_putchar('-');
	if (flags.dot >= 0)
		count += print_width(flags.dot - 1, ft_strlen(str_from_int) - 1, 1);
	count += print_str(str_from_int, ft_strlen(str_from_int));
	return (count);
}

static int	part_of_intfunction(char *str_from_int, int save_i, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += dotflag_handling(str_from_int, save_i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str_from_int))
		flags.dot = ft_strlen(str_from_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += print_width(flags.width, 0, 0);
	}
	else
		count += print_width(flags.width, ft_strlen(str_from_int), flags.zero);
	if (flags.minus == 0)
		count += dotflag_handling(str_from_int, save_i, flags);
	return (count);
}

int			int_handling_normal(int i, t_flags flags)
{
	char	*str_from_int;
	int		save_i;
	int		count;

	save_i = i;
	count = 0;
	if (flags.dot == 0 && i == 0)
	{
		count += print_width(flags.width, 0, 0);
		return (count);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == -1)
				print_str("-", 1);
		i *= -1;
		flags.width -= 1;
		count++;
	}
	str_from_int = ft_itoa(i);
	count += part_of_intfunction(str_from_int, save_i, flags);
	free(str_from_int);
	return (count);
}

int			int_handling(int i, t_flags flags)
{
	int count;

	count = 0;
	if (i == -2147483648)
	{
		i = -214748364;
		count += int_handling_normal(i, flags);
		count++;
		ft_putchar('8');
	}
	else
		count = int_handling_normal(i, flags);
	return (count);
}
