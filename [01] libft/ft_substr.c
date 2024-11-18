/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:40:03 by bportell          #+#    #+#             */
/*   Updated: 2024/11/11 15:01:20 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	s_len;
	size_t	size;
	size_t	i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		size = s_len - start;
	else
		size = len;
	subs = malloc((size + 1) * sizeof(char));
	if (subs == 0)
		return (NULL);
	i = 0;
	while (s[start + i] && i < size)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = 0;
	return (subs);
}
/*
#include <stdio.h>

int main (void)
{
	printf("the substring of 'banana is good' (s= 5, l= 4) is: %s\n", ft_substr("banana is good", 5, 4));
	printf("the substring of 'banana is good' (s= 1, l= 14) is: %s\n", ft_substr("banana is good", 1, 14));
	printf("the substring of 'banana is good' (s= 1, l= 10) is: %s\n", ft_substr("banana is good", 1, 10));
	printf("the substring of 'banana is good' (s= 0, l= 0) is: %s\n", ft_substr("banana is good", 0, 0));
	printf("the substring of 'banana is good' (s= 8, l= 12) is: %s\n", ft_substr("banana is good", 8, 12));
	printf("the substring of 'banana is good' (s= 0, l= 70) is: %s\n", ft_substr("banana is good", 0, 70));
}*/