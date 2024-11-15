/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:39:58 by bportell          #+#    #+#             */
/*   Updated: 2024/11/15 17:20:27 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//char	ft_ctoupper(unsigned int index, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = s[i];
	return (str);
}
/*
char	ft_ctoupper(unsigned int index, char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	index = index * 1;
	return (c);
}
#include <stdio.h>

int	main(void)
{
	char str[] = "abcdefg";

	printf("My str is: %s\n", str);
	printf("After ft_strmapi is: %s\n", ft_strmapi(str, ft_ctoupper));
	return (0);
}
*/