/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:34:47 by bportell          #+#    #+#             */
/*   Updated: 2024/11/15 12:38:41 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((i < n - 1) && (str1[i] || str2[i]) && (str1[i] == str2[i]))
		i++;
	return (str1[i] - str2[i]);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	test1[] = "ABe";
	const char	test2[] = "BCD";
	const char	test3[] = "123b";
	const char	test4[] = "123a";
	const char	test5[] = "wordS";
	const char	test6[] = "wordY";

	printf("text1:%s text2:%s\n", test1, test2);
	printf("n = 0; return: %d (mine)\n", ft_strncmp(test1, test2, 0));
	printf("n = 0; return: %d (correct)\n", strncmp(test1, test2, 0));
	printf("text1:%s text2:%s\n", test3, test4);
	printf("n = 3; return: %d (mine)\n", ft_strncmp(test3, test4, 3));
	printf("n = 3; return: %d (correct)\n", strncmp(test3, test4, 3));
	printf("text1:%s text2:%s\n", test5, test6);
	printf("n = 4; return: %d (mine)\n", ft_strncmp(test5, test6, 4));
	printf("n = 4; return: %d (correct)\n", strncmp(test5, test6, 4));
	return (0);
}
*/