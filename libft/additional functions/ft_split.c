/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:39:54 by bportell          #+#    #+#             */
/*   Updated: 2024/11/11 17:32:47 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libc/libft.h"

int		str_count(char const *s, char c);

/*char	**ft_split(char const *s, char c)
{
}*/
int	str_count(char const *s, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count) ;
}
#include <stdio.h>

int main (void)
{
	printf("the words are:  verão traquinas amigo cachorro (4)\n");
	printf("number of words is: %i\n", str_count(" verão    traquinas amigo cachorro",  ' '));
}