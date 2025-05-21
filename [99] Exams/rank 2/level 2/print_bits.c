/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:10:34 by bportell          #+#    #+#             */
/*   Updated: 2025/05/21 19:10:48 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
*/
#include <stdio.h>
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	mask;

	printf("%o\n", octet);
	mask = 7;         // o maior valor binário entre os 8 (0 a 7)
	while (mask >= 0) // enquanto o meu valor de mascara for maior que 0
	{
		if (octet & (1 << mask))
			//(1 << mask) é 1 que vai avançar para esquerda 7 casas
			// se o numero e 10000000 tiverem bits iguais, imprime 1
			write(1, "1", 1);
		else
			write(1, "0", 1);
		mask--;
	}
	return ;
}

// 00000001 inicio
// 00000010 mover 1 << 1
// 00000100 mover 1 << 2
// 00001000 mover 1 << 3
// 00010000 mover 1 << 4
// 00100000 mover 1 << 5
// 01000000 mover 1 << 6
// 10000000 mover 1 << 7

int	main(void)
{
	print_bits(255);
	return (0);
}
