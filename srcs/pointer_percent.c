/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:57:18 by eerika            #+#    #+#             */
/*   Updated: 2021/02/15 13:29:47 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	part_of_pointfunc(char *pointer, t_flags flags)
{
	int count;

	count = 0;
	count += print_str("0x", 2);
	if (flags.dot >= 0)
	{
		count += print_width(flags.dot, ft_strlen(pointer), 1);
		count += print_str(pointer, flags.dot);
	}
	else
		count += print_str(pointer, ft_strlen(pointer));
	return (count);
}

int			pointer_handling(unsigned long long ptr, t_flags flags)
{
	char	*pointer;
	int		count;

	count = 0;
	if (ptr == 0 && flags.dot == 0)
	{
		count = print_width(flags.width - 1, 1, 0);
		count += 2;
		ft_putchar('0');
		ft_putchar('x');
		return (count);

		// count += print_str("0x", 2);
		// return (count += print_width(flags.width, 0, 1));
	}
	pointer = num_to_hex(ptr, 0);
	pointer = ft_str_tolower(pointer);
	if ((size_t)flags.dot < ft_strlen(pointer))
		flags.dot = ft_strlen(pointer);
	if (flags.minus == 1)
		count += part_of_pointfunc(pointer, flags);
	count += print_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		count += part_of_pointfunc(pointer, flags);
	free(pointer);
	return (count);
}

int			percent_handling(t_flags flags)
{
	int		count;

	count = 0;
	if (flags.minus == 1)
		count += ft_putchar('%');
	count += print_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count += ft_putchar('%');
	return (count);
}
