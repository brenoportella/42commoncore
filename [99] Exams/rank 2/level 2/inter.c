/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:22:12 by bportell          #+#    #+#             */
/*   Updated: 2025/05/21 15:42:08 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/
#include <unistd.h>

void	_print_char_one(char *s1, char *s2)
{
	int	i;
	int	j;
	int	flag;

	if (!s1 || !s2)
		return ;
	i = 0;
	while (s1[i])
	{
		j = 0;
		flag = 0;
		while (j < i)
		{
			if (s1[j] == s1[i])
				flag = 1;
			j++;
		}
		if (flag == 0)
		{
			j = 0;
			while (s1[i] != s2[j] && s2[j])
				j++;
			if (s1[i] == s2[j])
			{
				write(1, &s1[i], 1);
				j++;
			}
		}
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		_print_char_one(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}
