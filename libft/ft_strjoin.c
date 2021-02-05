/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:33:08 by eerika            #+#    #+#             */
/*   Updated: 2020/11/25 19:40:34 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	l;
	size_t	i;

	res = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (res == NULL || (!s1 && !s2))
		return (NULL);
	i = 0;
	l = 0;
	while (s1[i] != '\0')
	{
		res[l] = s1[i];
		l++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		res[l] = s2[i];
		l++;
		i++;
	}
	res[l] = '\0';
	return (res);
}
