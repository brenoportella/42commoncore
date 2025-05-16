/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:51:12 by bportell          #+#    #+#             */
/*   Updated: 2025/05/16 15:02:39 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char	*ft_strcpy(char *s1, char *s2);
*/

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	if (!src || !dst)
		return (0);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
#include <stdio.h>

int	main(void)
{
	char	origem[] = "Hello, 42!";

	char destino[50]; // tamanho suficiente para copiar,
	printf("Destino: %s\n", destino);
	ft_strcpy(destino, origem);
	printf("Origem:  %s\n", origem);
	printf("Destino: %s\n", destino);
	return (0);
}
*/