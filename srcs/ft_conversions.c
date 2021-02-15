/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 11:21:47 by eerika            #+#    #+#             */
/*   Updated: 2021/02/15 13:28:39 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		istype(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
			|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int		isflags(int c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*')
		return (1);
	else
		return (0);
}

int		ft_conversions(int c, t_flags flags, va_list ap)
{
	int char_count;

	char_count = 0;
	if (c == 'c')
		char_count = char_handling(va_arg(ap, int), flags);
	else if (c == 's')
		char_count = string_handling(va_arg(ap, char *), flags);
	else if (c == 'p')
		char_count = pointer_handling(va_arg(ap, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		char_count = int_handling(va_arg(ap, int), flags);
	else if (c == 'u')
		char_count += uint_handling((unsigned int)va_arg(ap, unsigned int),
		flags);
	else if (c == 'x')
		char_count += hexa_handling(va_arg(ap, unsigned int), 1, flags);
	else if (c == 'X')
		char_count += hexa_handling(va_arg(ap, unsigned int), 0, flags);
	else if (c == '%')
		char_count += percent_handling(flags);
	return (char_count);
}
