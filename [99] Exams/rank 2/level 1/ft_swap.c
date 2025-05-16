/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:05:34 by bportell          #+#    #+#             */
/*   Updated: 2025/05/16 15:11:44 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);
*/

void	ft_swap(int *a, int *b)
{
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

#include <stdio.h>

int main (void)
{
	int a;
	int b;
	
	a = 9;
	b = 6;
	printf("a = %i\n", a);
	printf("b = %i\n", b);
	ft_swap(&a, &b);
	printf("SWAP\n"); 
	printf("a = %i\n", a);
	printf("b = %i\n", b);
}
