/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:50:23 by bportell          #+#    #+#             */
/*   Updated: 2024/11/18 14:26:01 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*d_str;

	i = 0;
	d_str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (d_str == NULL)
		return (0);
	while (s[i])
	{
		d_str[i] = s[i];
		i++;
	}
	d_str[i] = s[i];
	return (d_str);
}
/*
#include "stdio.h"

int	main(void)
{
	char	src[] = "can i duplicate this??";

	printf("The src string (char) is: %s\n", src);
	printf("The duplicate string is: %s\n", ft_strdup(src));
}
*/