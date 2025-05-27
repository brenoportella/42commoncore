/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:35:27 by bportell          #+#    #+#             */
/*   Updated: 2025/05/27 16:35:50 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int	*ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h>

int	absnum(int num)
{
	if (num < 0)
		num = -num;
	return (num);
}
int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*range;

	len = absnum(end - start) + 1;
	range = (int *)malloc(len * sizeof(int));
	if (!range)
		return (NULL);
	i = 0;
	while(i < len)
	{
		if (end >= start)
			range[i] = start + i;
		if (end <= start)
			range[i] = start - i;
		i++;
	}
	return (range);
}
#include <stdio.h>

int	main(void)
{
	int i;
	int len;
	int *range;
	int a;
	int b;

	a = 9;
	b = 0;
	i = 0;
	len = absnum(a - b) + 1;
	range = ft_range(a, b);
	while (i < len)
	{
		printf("%i\n", range[i]);
		i++;
	}
	return (0);
}