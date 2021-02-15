/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:57:42 by eerika            #+#    #+#             */
/*   Updated: 2021/02/15 13:28:11 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			char_handling(char c, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	count = print_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	count += 1;
	return (count);
}

static int	part_of_strfunction(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += print_width(flags.dot, ft_strlen(str), 0);
		count += print_str(str, flags.dot);
	}
	else
		count += print_str(str, ft_strlen(str));
	return (count);
}

int			string_handling(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count += part_of_strfunction(str, flags);
	if (flags.dot >= 0)
		count += print_width(flags.width, flags.dot, 0);
	else
		count += print_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		count += part_of_strfunction(str, flags);
	return (count);
}
