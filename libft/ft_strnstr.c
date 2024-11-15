/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:34:53 by bportell          #+#    #+#             */
/*   Updated: 2024/11/15 12:38:52 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *tofind, size_t len)
{
	char	*str;
	size_t i;     /*iteração para cada ponto inicial*/
	size_t start; /*ponto inicial da iteração*/
	
	start = 0;
	str = (char *)src;
	if (tofind[0] == '\0')
		return (str);
	while (str[start] && start < len)
	{
		i = 0;
		if (str[start] == tofind[i])
		{
			while (str[start + i] == tofind[i] && tofind[i] && start + i < len)
				i++;
			if (tofind[i] == '\0')
				return (&str[start]);
		}
		start++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strnstr("breno portella", "no", 5));
}
*/
