/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:18:56 by bportell          #+#    #+#             */
/*   Updated: 2025/05/29 10:50:22 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/
#include <stdlib.h>

int	nbrlen(long nbr)
{
	int	size;

	size = 0;
	if (nbr < 0)
	{
		size++;
		nbr = -nbr;
	}
	if (nbr > 0)
	{
		while (nbr > 9)
		{
			nbr = nbr / 10;
			size++;
		}
		if (nbr < 10)
			size++;
	}
	return (size);
}

char	*ft_itoa(int nbr)
{
	int	len;
	char	*str;
	long	lnbr;
	
	lnbr = (long)nbr;
	len = nbrlen(lnbr);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return NULL;
	if (nbr == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (lnbr < 0)
	{
		str[0] = '-';
		lnbr = -lnbr;
	}
	while (lnbr)
	{
		str[--len] = (lnbr % 10) + '0';
		lnbr = lnbr / 10;
	}

	return (str);
}
#include <stdio.h>

int	main(void)
{
	char *str;

	str = ft_itoa(-2147483648);
	printf("%s\n", str);
	free (str);
	return (0);
}