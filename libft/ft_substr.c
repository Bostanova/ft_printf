/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:18:31 by eerika            #+#    #+#             */
/*   Updated: 2020/11/15 14:20:29 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned	i;
	char		*res;

	i = 0;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL || !s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		res[0] = '\0';
		return (res);
	}
	while (s[start] != '\0' && i < len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
	free(res);
}
