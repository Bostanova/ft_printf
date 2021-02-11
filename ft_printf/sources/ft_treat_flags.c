/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:58:33 by eerika            #+#    #+#             */
/*   Updated: 2021/02/11 18:06:39 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags		ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flags		ft_flag_width(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

int			ft_flag_dot(const char *save, int start,
			t_flags *flags, va_list args)
{
	start++;
	if (save[start] == '*')
	{
		flags->dot = va_arg(args, int);
		start++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(save[start]))
		{
			flags->dot = (flags->dot * 10) + (save[start] - '0');
			start++;
		}
	}
	return (start);
}
