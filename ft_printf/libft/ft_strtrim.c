/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:31:25 by eerika            #+#    #+#             */
/*   Updated: 2020/11/26 23:07:32 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//освободить при помощи free память во всех файлах
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	len;
	char *res;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (i == len || len == 0)
		return (ft_strdup(""));
	while (len > 0 && ft_strchr(set, s1[len]))
		len--;
	res = ft_substr((char *)s1, i, len - i + 1);
	return (res);
}

#include <stdio.h>
#include <string.h>
int main(void)
{
    printf("%s\n", ft_strtrim("jjfhjvfjdkj", "jk"));
    return 0;
}