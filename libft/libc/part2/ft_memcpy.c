/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:57:30 by bportell          #+#    #+#             */
/*   Updated: 2024/11/04 15:39:29 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*c_dest;
	unsigned char	*c_src;

	c_src = (unsigned char *)src;
	c_dest = (unsigned char *)dest;
	i = 0;
	while (i < (int)n && (c_src || c_dest))
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "Testando memcpy personalizado";
	char	dest[30];

	printf("Antes da cópia:\n");
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest);
	ft_memcpy(dest, src, strlen(src) + 1);
	printf("\nDepois da cópia:\n");
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest);
	return (0);
}
*/