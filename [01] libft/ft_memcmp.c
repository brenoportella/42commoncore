/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:34:44 by bportell          #+#    #+#             */
/*   Updated: 2024/11/15 12:35:41 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((i < n - 1) && (str1[i] == str2[i]))
		i++;
	return (str1[i] - str2[i]);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("The memcmp is: %i", ft_memcmp("abcdfg", "abcdef", 0));
}
*/