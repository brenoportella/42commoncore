/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:57:30 by bportell          #+#    #+#             */
/*   Updated: 2024/10/31 14:04:27 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*c_dest;
	unsigned char	*c_src;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	c_src = (unsigned char *)src;
	c_dest = (unsigned char *)dest;
	while (n > 0)
	{
		*(c_dest++) = *(c_src++);
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char src[] = "Testando memcpy personalizado";
	char dest[30];

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