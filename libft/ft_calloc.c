/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:38:19 by eerika            #+#    #+#             */
/*   Updated: 2020/11/22 19:20:06 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	char	*res;
	size_t	total;

	i = 0;
	total = count * size;
	res = malloc(total);
	if (res == NULL)
		return (NULL);
	while (total--)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}
