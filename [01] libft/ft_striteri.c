/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:39:55 by bportell          #+#    #+#             */
/*   Updated: 2024/11/15 17:52:43 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void	ft_plusone(unsigned int index, char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
/*
void	ft_plusone(unsigned int index, char *s)
{
	*s += index;
}

#include <stdio.h>

int main()
{
	char	str[] = "aaaaaaaaaa";
	
	printf("original str is: %s\n", str);
	ft_striteri(str, ft_plusone);
	printf("after ft_striteri: %s\n", str);
}
*/