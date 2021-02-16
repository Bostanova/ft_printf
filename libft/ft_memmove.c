/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:35:50 by eerika            #+#    #+#             */
/*   Updated: 2021/02/16 09:40:35 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*res;
	unsigned char	*str;

	res = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (src < dst)
	{
		while (len--)
			res[len] = str[len];
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
