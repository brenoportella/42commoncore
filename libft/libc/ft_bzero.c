/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:36:13 by bportell          #+#    #+#             */
/*   Updated: 2024/10/29 15:11:05 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
void	ft_bzero(void *s, size_t n);

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	unsigned int	i;

	if (s == 0 || n <= 0)
		return ;
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
//ptr = (unsigned char *)s;//convert the generic ptr to unsigned char
#include <stdio.h>
#include <strings.h>

int	main(void)
{
	char	str[] = "breno";

	printf("%s \n", str);
	ft_bzero(str, 3);
	printf("%s \n", str);
}
*/