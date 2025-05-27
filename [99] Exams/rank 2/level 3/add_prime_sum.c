/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:56:01 by bportell          #+#    #+#             */
/*   Updated: 2025/05/27 10:49:24 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/
#include <unistd.h>

void	putnbr(int num)
{
	char	c;

	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num > 9)
		putnbr(num / 10);
	c = num % 10 + 48;
	write(1, &c, 1);
}
int	is_prime(int num)
{
	int	i;

	i = 2;
	if (num <= 1)
		return (0);
	if (num >= 2)
	{
		while (i < num)
		{
			if (num % i == 0)
				return (0);
			i++;
		}
	}
	return (1);
}

int	sum_primes(int num)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (i <= num)
	{
		if (is_prime(i))
		{
			res += i;
		}
		i++;
	}
	return (res);
}
int	ft_atoi(char *str)
{
	int	num;
	int	i;
	int	signal;

	i = 0;
	signal = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal = -signal;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * signal);
}
int	main(int argc, char **argv)
{
	int prime;
	
	if (argc == 2)
	{
		prime = sum_primes(ft_atoi(argv[1]));
		putnbr(prime);
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);
	return (0);
}