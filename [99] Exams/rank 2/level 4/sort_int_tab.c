/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:02:07 by bportell          #+#    #+#             */
/*   Updated: 2025/05/29 12:06:54 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/

void	sort_int_tab(int *tab, unsigned int size)
{
	int	temp;
	int	sorted;
	unsigned int	i;
	
	if (size < 2 || !tab)
		return;
	sorted = 0;
	while(!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = temp;
				sorted = 0;
			}
			i++;
		}
	}
}
#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size);

int main(void)
{
	int arr[] = {5};
	unsigned int size = sizeof(arr) / sizeof(arr[0]);

	sort_int_tab(arr, size);

	for (unsigned int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
