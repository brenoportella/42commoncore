/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:34:19 by bportell          #+#    #+#             */
/*   Updated: 2024/11/08 17:01:46 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size < dest_len)
		return (size + src_len);
	i = 0;
	while (src[i] && (dest_len + i) < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = 0;
	return (dest_len + src_len);
}
/*
#include <stdio.h>

int	main(void)
{
	char a[] = "Breno Portella";  // src
	char b[50] = "ABCDEFG"; // dest
	printf("BEFORE FT_MEMMOVE:\nThe src array is: %s\nThe dest array is: %s\n",
		a, b);
	ft_strlcat(b, a, 50);
	printf("AFTER FT_MEMMOVE\nThe src array is: %s\nThe dest array is: %s\n", a,
		b);
}
*/