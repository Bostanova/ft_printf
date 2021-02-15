/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:32:23 by eerika            #+#    #+#             */
/*   Updated: 2021/02/15 20:09:04 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	numlen(long n)
{
	long i;

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

char	*ft_itoa(int n)
{
	char	*res;
	long	num;
	int		i;

	num = n;
	// if (num == -2147483648)
	// 	num = 2147483648;
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
