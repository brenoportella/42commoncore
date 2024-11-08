/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:58:18 by bportell          #+#    #+#             */
/*   Updated: 2024/11/08 17:01:28 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *s, int c, size_t n);

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>

int	main(void)
{
	char	buffer[20];

	printf("Buffer before ft_memset: %s\n", buffer);
	// Preenche o buffer com o caractere 'A' (valor ASCII 65)
	ft_memset(buffer, 'B', sizeof(buffer) - 1);
	// Coloca um caractere nulo no final para facilitar a impressão
	buffer[19] = '\0';
	// Exibe o buffer
	printf("Buffer after ft_memset: %s\n", buffer);
	// Verifica se cada byte foi preenchido corretamente
	for (int i = 0; i < 19; i++) {
		if (buffer[i] != 'A') {
			printf("Error: buffer[%d] is not 'A'\n", i);
			return (1);
		}
	}
	printf("Test passed! All bytes correctly set to 'A'.\n");
	return (0);
}
*/