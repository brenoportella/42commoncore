/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:39:57 by bportell          #+#    #+#             */
/*   Updated: 2024/11/11 15:23:02 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i1;
	size_t	i2;
	char	*str;

	i1 = 0;
	i2 = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	while (s1[i1])
	{
		str[i1] = s1[i1];
		i1++;
	}
	while (s2[i2])
	{
		str[i1 + i2] = s2[i2];
		i2++;
	}
	str[i1 + i2] = 0;
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char *s1 = "banana i";
	char *s2 = "s good!";

	printf("The s1 is: %s\n", s1);
	printf("The s2 is: %s\n", s2);
	printf("The join is: %s\n", ft_strjoin(s1, s2));
}
*/