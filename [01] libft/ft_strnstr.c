/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:34:53 by bportell          #+#    #+#             */
/*   Updated: 2024/11/18 20:10:44 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *tofind, size_t len)
{
	char	*str;
	size_t	i;
	size_t	start;

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
