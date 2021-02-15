/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:53:39 by eerika            #+#    #+#             */
/*   Updated: 2021/02/15 13:33:41 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*num_to_hex(unsigned long long value, int count)
{
	char				*res;
	unsigned long long	copy;

	res = 0;
	copy = value;
	if (value == 0)
		return (ft_strdup("0"));
	while (value != 0)
	{
		value /= 16;
		count++;
	}
	if (!(res = malloc(sizeof(char) * (count + 1))))
		return (0);
	res[count] = '\0';
	while (copy != 0)
	{
		if ((copy % 16) < 10)
			res[count - 1] = (copy % 16) + 48;
		else
			res[count - 1] = (copy % 16) + 55;
		copy /= 16;
		count--;
	}
	return (res);
}

char		*ft_str_tolower(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}

static	int	part_of_hexa(char *hexa, t_flags flags, int count)
{
	if (flags.minus == 1)
	{
		if (flags.dot >= 0)
			count += print_width(flags.dot - 1, ft_strlen(hexa) - 1, 1);
		count += print_str(hexa, ft_strlen(hexa));
	}
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hexa))
		flags.dot = ft_strlen(hexa);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += print_width(flags.width, 0, 0);
	}
	else
		count += print_width(flags.width,
		ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
	{
		if (flags.dot >= 0)
			count += print_width(flags.dot - 1, ft_strlen(hexa) - 1, 1);
		count += print_str(hexa, ft_strlen(hexa));
	}
	return (count);
}

int			hexa_handling(unsigned int num, int height, t_flags flags)
{
	char	*hex;
	int		count;

	count = 0;
	num = (unsigned int)(4294967295 + 1 + num);
	if (flags.dot == 0 && num == 0)
	{
		count += print_width(flags.width, 0, 0);
		return (count);
	}
	hex = num_to_hex((unsigned long long)num, 0);
	if (height == 1)
		hex = ft_str_tolower(hex);
	count += part_of_hexa(hex, flags, 0);
	free(hex);
	return (count);
}
