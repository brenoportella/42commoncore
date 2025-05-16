/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:20:04 by bportell          #+#    #+#             */
/*   Updated: 2025/05/16 16:04:13 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

int	index_alpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 1);
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 1);
	return (1);
}
void	ft_putchr(char c)
{
	write(1, &c, 1);
}
void	write_n_times(char c, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		ft_putchr(c);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	int	i;
	int	index;

	if (argc != 2)
	{
		ft_putchr('\n');
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		index = index_alpha(argv[1][i]);
		write_n_times(argv[1][i], index);
		i++;
	}
	ft_putchr('\n');
	return (0);
}
