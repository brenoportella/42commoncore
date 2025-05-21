/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:46:29 by bportell          #+#    #+#             */
/*   Updated: 2025/05/21 16:03:14 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2,
	otherwise it returns 0.

Your function must be declared as follows:

int	is_power_of_2(unsigned int n);
*/

int	is_power_of_2(unsigned int n)
{
	unsigned int	res;

	res = 1;
	while (res < n)
		res *= 2;
	return (res == n);
}

#include <stdio.h>

int	main(void)
{
	printf("0 %i\n", is_power_of_2(0));
	printf("1 %i\n", is_power_of_2(1));
	printf("2 %i\n", is_power_of_2(2));
	printf("3 %i\n", is_power_of_2(3));
	printf("4 %i\n", is_power_of_2(4));
	printf("5 %i\n", is_power_of_2(5));
	printf("6 %i\n", is_power_of_2(6));
	printf("7 %i\n", is_power_of_2(7));
	printf("8 %i\n", is_power_of_2(8));
	printf("16 %i\n", is_power_of_2(16));
	printf("32 %i\n", is_power_of_2(32));
	printf("64 %i\n", is_power_of_2(64));
	return (0);
}