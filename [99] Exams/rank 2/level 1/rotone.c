/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:06:34 by bportell          #+#    #+#             */
/*   Updated: 2025/05/16 17:08:46 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
*/


#include <unistd.h>

void	min_rotone(char c)
{
	if ((c >= 'a' && c <= 'z'))
	{
		if (c + 1 <= 'z')
		{
			c += 1;
			write(1, &c, 1);
		}
		else if (c + 1 > 'z')
		{
			c += 1 - 26;
			write(1, &c, 1);
		}
	}
	return ;
}

void	max_rotone(char c)
{
	if ((c >= 'A' && c <= 'Z'))
	{
		if (c + 1 <= 'Z')
		{
			c += 1;
			write(1, &c, 1);
		}
		else if (c + 1 > 'Z')
		{
			c += 1 - 26;
			write(1, &c, 1);
		}
	}
	return ;
}

int	main(int argc, char **argv)
{
	int i;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			min_rotone(argv[1][i]);
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			max_rotone(argv[1][i]);
		else if (argv[1][i] > 31 && argv[1][i] < 127)
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
