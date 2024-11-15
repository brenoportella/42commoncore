/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:39:43 by bportell          #+#    #+#             */
/*   Updated: 2024/11/15 12:35:02 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nmb_len(long n);

char	*ft_itoa(int n)
{
	char	*number;
	int		i;
	long	nmb;

	nmb = n;
	i = ft_nmb_len(nmb);
	number = malloc((i + 1) * sizeof(char));
	if (!number) 
		return (NULL);
	number[i] = '\0';
	if (nmb < 0)
	{
		number[0] = '-';
		nmb = -nmb;
	}
	while (nmb > 9)
	{
		number[--i] = (nmb % 10) + 48;
		nmb /= 10;
	}
	number[--i] = nmb + 48;
	return (number);
}
static int	ft_nmb_len(long n)
{
	int len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= 1)
	{
		n /= 10;
		len++;
	}
	return (len);
}
/*
#include <stdio.h>

int main (void)
{
	int		n;

	n = 0;
	printf("the lenght of the number is %i\n", ft_nmb_len(n));
	printf("the number original is %i\n", n);
	printf("the number in char is %s\n", ft_itoa(n));
}
*/