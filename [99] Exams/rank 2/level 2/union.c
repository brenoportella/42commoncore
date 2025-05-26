/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:56:01 by bportell          #+#    #+#             */
/*   Updated: 2025/05/26 14:40:12 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$ zpadintopaqefwtjy
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/
#include <unistd.h>

int	is_double_char(char c, char *str, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
void	_union(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	while (str1[i])
	{
		if (!is_double_char(str1[i], str1, i))
			write(1, &str1[i], 1);
		i++;
	}
	j = 0;
	while (str2[j])
	{
		if (!is_double_char(str2[j], str1, i) && !is_double_char(str2[j], str2,
				j))
			write(1, &str2[j], 1);
		j++;
	}
	return ;
}
int	main(int argc, char **argv)
{
	if (argc == 3)
		_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}