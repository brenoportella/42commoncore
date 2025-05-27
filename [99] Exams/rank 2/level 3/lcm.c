/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:04:19 by bportell          #+#    #+#             */
/*   Updated: 2025/05/27 15:11:36 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);
*/

unsigned int	_pgcd(unsigned int a, unsigned int b)
{
	unsigned int	swap;

	while (b > 0)
	{
		swap = a % b;
		a = b;
		b = swap;
	}
	return (a);
}
unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	lcm;
	unsigned int	pgcd;

	if (!a || !b)
		return (0);
	pgcd = _pgcd(a, b);
	lcm = (a * b) / pgcd;
	return (lcm);
}
#include <stdio.h>

int	main(void)
{
	unsigned int a, b;

	a = 12;
	b = 18;
	printf("LCM de %u e %u é %u\n", a, b, lcm(a, b));

	a = 7;
	b = 5;
	printf("LCM de %u e %u é %u\n", a, b, lcm(a, b));

	a = 21;
	b = 6;
	printf("LCM de %u e %u é %u\n", a, b, lcm(a, b));

	a = 0;
	b = 5;
	printf("LCM de %u e %u é %u\n", a, b, lcm(a, b)); // deve ser 0

	return (0);
}