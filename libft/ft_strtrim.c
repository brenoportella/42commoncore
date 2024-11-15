/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:40:02 by bportell          #+#    #+#             */
/*   Updated: 2024/11/11 16:20:05 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, char const *set);

char	*ft_strtrim(const char *s1, char const *set)
{
	int		start;
	int		end;
	char	*strimmed;

	start = 0;
	end = (int)ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_in_set(s1[start], set))
		start++;
	while (end > start && ft_in_set(s1[end - 1], set))
		end--;
	strimmed = malloc((end - start + 1) * sizeof(char));
	if (!strimmed)
		return (NULL);
	ft_strlcpy(strimmed, &s1[start], end - start + 1);
	return (strimmed);
}

static int	ft_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("String dirty: 'abababaabaabaLince is a little catabababbabb'\n");
	printf("String trimmed: %s\n",
		ft_strtrim("abababaabaabaLince is a little catabababbabb", "ab"));
}
*/