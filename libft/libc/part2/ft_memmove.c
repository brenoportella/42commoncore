/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:01:21 by bportell          #+#    #+#             */
/*   Updated: 2024/11/04 15:16:32 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int i;
	unsigned char *p_dest;
	unsigned char *p_src;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	if (p_dest < p_src && (p_dest || p_src))
	{
		i = 0;
		while (i < (int)n)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	else if (p_dest > p_src && (p_dest || p_src))
	{
		while ((int)n > 0)
		{
			p_dest[n - 1] = p_src[n - 1];
			n--;
		}
	}
	return (dest);
}
#include <stdio.h>

int	main(void)
{
	char a[] = "Breno Portella";  // src
	char b[] = "ABCDEFGHIJKLMNO"; // dest

	printf("BEFORE FT_MEMMOVE:\nThe src array is: %s\nThe dest array is: %s\n",
		a, b);
	ft_memmove(b, a, 10);
	printf("AFTER FT_MEMMOVE\nThe src array is: %s\nThe dest array is: %s\n", a,
		b);
}
