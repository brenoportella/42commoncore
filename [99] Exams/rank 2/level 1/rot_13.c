/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:20:39 by bportell          #+#    #+#             */
/*   Updated: 2025/05/16 16:53:29 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
*/

#include <unistd.h>

void	min_rot_13(char c)
{
	if ((c >= 'a' && c <= 'z'))
	{
		if (c + 13 <= 'z')
		{
			c += 13;
			write(1, &c, 1);
		}
		else if (c + 13 > 'z')
		{
			c += 13 - 26;
			write(1, &c, 1);
		}
	}
	return ;
}

void	max_rot_13(char c)
{
	if ((c >= 'A' && c <= 'Z'))
	{
		if (c + 13 <= 'Z')
		{
			c += 13;
			write(1, &c, 1);
		}
		else if (c + 13 > 'Z')
		{
			c += 13 - 26;
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
			min_rot_13(argv[1][i]);
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			max_rot_13(argv[1][i]);
		else if (argv[1][i] > 31 && argv[1][i] < 127)
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
