/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:20:46 by bportell          #+#    #+#             */
/*   Updated: 2025/05/21 18:06:36 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int	max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

int	max(int *tab, unsigned int len)
{
	int	largest;
	unsigned int	i;

	if (!tab || len == 0)
		return (0);
	i = 0;
	largest = tab[i];
	while (i < len)
	{
		if (tab[i] > largest)
			largest = tab[i];
		i++;
	}
	return (largest);
}
#include <stdio.h>

int	main(void)
{
	int tab[5] = {13, 2, 1, 12, 4};
	printf("the largest is: %i\n", max(tab, 5));

	return (0);
}