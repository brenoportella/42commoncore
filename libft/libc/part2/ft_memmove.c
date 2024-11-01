/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:34:11 by bportell          #+#    #+#             */
/*   Updated: 2024/10/31 17:51:03 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*n_dest;
	unsigned char	*n_src;

	n_src = (unsigned char *)src;
	n_dest = (unsigned char *)dest;
	i = 0;
	/* checking if the pointers are null */
	if (!dest || !src)
		return NULL;
	if (n_dest > n_src)
		while (n-- > 0)
			n_dest[n] = n_src[n];
	else
	{
		while (i++ < n)
			n_dest[i] = n_src[i];
	}
	return (dest);
}
#include <stdio.h>

int	main(void)
{
	char a[] = "Breno Portella";  // src
	char b[] = "ruidoruid"; // dest

	printf("BEFORE FT_MEMMOVE:\nThe src array is: %s\nThe dest array is: %s\n",
		a, b);
	ft_memmove(b, a, 10);
	printf("AFTER FT_MEMMOVE\nThe src array is: %s\nThe dest array is: %s\n", a,
		b);
}