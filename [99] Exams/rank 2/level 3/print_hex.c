/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:16:27 by bportell          #+#    #+#             */
/*   Updated: 2025/05/27 15:29:29 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

// converter string para numero = unsigned int ft_atoi(char *str)
// converter inteiro para hex = void putnbr_base(unsigned int n, char *base)

void	putnbr_base(unsigned int n, char *base)
{
	char	c;

	if (n >= 16)
	{
		putnbr_base(n / 16, base);
	}
	c = base[n % 16];
	write(1, &c, 1);
	return ;
}
unsigned int	ft_atoi(char *str)
{
	unsigned int	res;
	unsigned int	i;

	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		putnbr_base(ft_atoi(argv[1]), "0123456789abcdef");
	}
	write(1, "\n", 1);
	return (0);
}