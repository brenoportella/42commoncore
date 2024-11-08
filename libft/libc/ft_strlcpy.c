/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:34:23 by bportell          #+#    #+#             */
/*   Updated: 2024/11/08 17:01:56 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (src_len);
}
/*
#include <stdio.h>

int	main(void)
{
	char a[] = "Breno Portella";  // src
	char b[] = "ABCDEFGHIJKLMNO"; // dest
	printf("BEFORE FT_MEMMOVE:\nThe src array is: %s\nThe dest array is: %s\n",
		a, b);
	ft_strlcpy(b, a, 13);
	printf("AFTER FT_MEMMOVE\nThe src array is: %s\nThe dest array is: %s\n", a,
		b);
}
*/