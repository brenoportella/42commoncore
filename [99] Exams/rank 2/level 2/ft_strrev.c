/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:56:13 by bportell          #+#    #+#             */
/*   Updated: 2025/05/21 13:14:33 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char	*ft_strrev(char *str);

*/

char	*ft_strrev(char *str)
{
	char	swap;
	int		i;
	int		j;

	i = 0;
	if (str[i])
	{
		while (str[i] != '\0')
			i++;
		j = 0;
		i -= 1;
		while (i > j)
		{
			swap = str[i];
			str[i] = str[j];
			str[j] = swap;
			i--;
			j++;
		}
	}
	return (str);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s\n", ft_strrev(argv[1]));
	return (0);
}