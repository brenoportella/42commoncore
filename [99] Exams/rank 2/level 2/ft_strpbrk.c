/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:08:05 by bportell          #+#    #+#             */
/*   Updated: 2025/05/21 12:50:29 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);
*/
#include <stdlib.h>
char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i] != s2[j] && s2[j])
			j++;
		if (s1[i] == s2[j])
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("my string: %s\n", argv[1]);
		printf("my find caracters: %s\n", argv[2]);
		printf("OG position found: %s\n", strpbrk(argv[1], argv[2]));
		printf("MY position found: %s\n", ft_strpbrk(argv[1], argv[2]));
	}
	return (0);
}