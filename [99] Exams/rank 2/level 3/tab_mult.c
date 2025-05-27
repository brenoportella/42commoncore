/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:40:07 by bportell          #+#    #+#             */
/*   Updated: 2025/05/27 14:58:39 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>*/

#include <unistd.h>

void	print_tab(unsigned int n);
void	putnbr(unsigned int n);
unsigned int	ft_atoi(char *str);


void	print_tab(unsigned int n)
{
	unsigned int	i;

	i = 1;
	while (i < 10)
	{
		putnbr(i);
		write(1, " x ", 3);
		putnbr(n);
		write(1, " = ", 3);
		putnbr(i * n);
		write(1, "\n", 1);
		i++;
	}
}
void	putnbr(unsigned int n)
{
	char	c;

	if (n > 9)
		putnbr(n / 10);
	c = n % 10 + 48;
	write(1, &c, 1);
}
unsigned int	ft_atoi(char *str)
{
	unsigned int	res;
	unsigned int	i;
	
	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		print_tab(ft_atoi(argv[1]));
	}
	else
		write(1, "\n", 1);
	return (0);
}