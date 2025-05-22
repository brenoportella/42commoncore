/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:22:21 by bportell          #+#    #+#             */
/*   Updated: 2025/05/22 12:13:13 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
		||
		\/
 0110  0100
*/

#include <unistd.h>

unsigned char	reverse_bits(unsigned char octed)
{
	unsigned char	res;
	unsigned char	bit;
	int				i;

	i = 0;
	res = 0;
	while (i < 8)
	{
		bit = (octed >> i) & 1;
		// isso aqui determina se o bit da posição i é 1 ou 0
		res = res | (bit << (7 - i));
		// isso aqui determina o resultado igual ao que está no bit na posição do maior pro menor.
		i++;
	}
	return (res);
}
void	print_bits(unsigned char octet)
{
	int	mask;

	mask = 7;
	while (mask >= 0)
	{
		if (octet & (1 << mask))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		mask--;
	}
	return ;
}
int	main(void)
{
	print_bits(reverse_bits(72));
	return (0);
}