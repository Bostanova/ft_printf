/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:35:05 by eerika            #+#    #+#             */
/*   Updated: 2021/02/15 14:44:11 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		flags_initial(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

static int	flag_parsing(const char *format, int i, t_flags *flags, va_list ap)
{
	while (format[i])
	{
		if (!ft_isdigit(format[i]) && !istype(format[i])
		&& !isflags(format[i]))
			break ;
		if (format[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (format[i] == '.')
			i = flag_dot(format, i, flags, ap);
		if (format[i] == '-')
			*flags = flag_minus(*flags);
		if (format[i] == '*')
			*flags = flag_width(ap, *flags);
		if (ft_isdigit(format[i]))
			*flags = flag_digit(format[i], *flags);
		if (istype(format[i]))
		{
			flags->type = format[i];
			break ;
		}
		i++;
	}
	return (i);
}

static int	format_parsing(const char *format, va_list ap)
{
	int			i;
	t_flags		flags;
	int			count;

	i = 0;
	count = 0;
	while (1)
	{
		flags = flags_initial();
		if (!format[i])
			break ;
		else if (format[i] == '%' && format[i + 1])
		{
			i = flag_parsing(format, ++i, &flags, ap);
			if (istype(format[i]))
				count += ft_conversions((char)flags.type, flags, ap);
			else if (format[i])
				count += ft_putchar(format[i]);
		}
		else if (format[i] != '%')
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}

int			ft_printf(const char *input, ...)
{
	const char	*format;
	va_list		ap;
	int			count;

	count = 0;
	format = ft_strdup(input);
	va_start(ap, input);
	count += format_parsing(format, ap);
	va_end(ap);
	free((char *)format);
	return (count);
}
