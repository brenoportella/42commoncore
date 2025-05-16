/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:35:18 by bportell          #+#    #+#             */
/*   Updated: 2025/05/16 14:28:49 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5,
	it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>
*/

#include <unistd.h>

void	print_number(int number)
{
	char	c;

	if (number < 0)
		return ;
	if (number > 9)
		print_number(number / 10);
	c = number % 10 + 48;
	write(1, &c, 1);
	return ;
}

int	main(void)
{
	int number;

	number = 1;

	while (number <= 100)
	{
		if (number % 3 == 0) /*multiplo de 3*/
			write(1, "fizz", 4);
		if (number % 5 == 0) /*multiplo de 5*/
			write(1, "buzz", 4);
		if (number % 5 != 0 && number % 3 != 0)
			print_number(number);
		write(1, "\n", 1);
		number++;
	}
}
