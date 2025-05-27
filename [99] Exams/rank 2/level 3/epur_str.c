/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:52:46 by bportell          #+#    #+#             */
/*   Updated: 2025/05/27 11:19:27 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat
	-e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>
*/

#include <unistd.h>

int	existe_outra_palavra(char *str, int pos)
{
	while (str[pos])
	{
		while (str[pos] == ' ' || str[pos] == '\t')
			pos++;
		if (str[pos] && str[pos] != ' ' && str[pos] != '\t')
			return (1);
	}
	return (0);
}

void	put_pur_str(char *str)
{
	int	i;
	int	need_space;

	need_space = 0;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i] && need_space == 0)
		i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i])
		{
			while (str[i] != ' ' && str[i])
			{
				write(1, &str[i], 1);
				i++;
			}
			need_space = 1;
		}
		if (str[i] == ' ' && need_space == 1)
		{
			if (existe_outra_palavra(str, i))
			{
				write(1, " ", 1);
			}
			i++;
			need_space = 0;
		}
		if (str[i] == ' ' && need_space == 0)
			i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		put_pur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}