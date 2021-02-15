/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsignint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:58:12 by eerika            #+#    #+#             */
/*   Updated: 2021/02/15 13:30:04 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	numlen(long n)
{
	long	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_unsigned_itoa(unsigned int n)
{
	char	*res;
	long	num;
	int		i;

	num = n;
	i = numlen(num);
	res = (char *)malloc(i + 1);
	if (res == NULL)
		return (NULL);
	res[i--] = '\0';
	if (num == 0)
		res[0] = '0';
	if (num < 0)
	{
		res[0] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		res[i] = '0' + (num % 10);
		num = num / 10;
		i--;
	}
	return (res);
}

static int	part_of_uintfunc(char *unsi_int, t_flags flags, int count)
{
	if (flags.minus == 1)
	{
		if (flags.dot >= 0)
			count += print_width(flags.dot - 1, ft_strlen(unsi_int) - 1, 1);
		count += print_str(unsi_int, ft_strlen(unsi_int));
	}
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(unsi_int))
		flags.dot = ft_strlen(unsi_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += print_width(flags.width, 0, 0);
	}
	else
		count += print_width(flags.width,
		ft_strlen(unsi_int), flags.zero);
	if (flags.minus == 0)
	{
		if (flags.dot >= 0)
			count += print_width(flags.dot - 1, ft_strlen(unsi_int) - 1, 1);
		count += print_str(unsi_int, ft_strlen(unsi_int));
	}
	return (count);
}

int			uint_handling(unsigned int num, t_flags flags)
{
	char	*unsi_int;
	int		count;

	count = 0;
	num = (unsigned int)(4294967295 + 1 + num);
	if (flags.dot == 0 && num == 0)
	{
		count += print_width(flags.width, 0, 0);
		return (count);
	}
	unsi_int = ft_unsigned_itoa(num);
	count += part_of_uintfunc(unsi_int, flags, 0);
	free(unsi_int);
	return (count);
}
