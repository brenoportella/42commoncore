/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:55:27 by bportell          #+#    #+#             */
/*   Updated: 2025/05/22 16:51:35 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
		\ /
		/ \
 0001 | 0100
*/

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet << 4) | octet >> 4);
}

// considerando que o numero é 0110 1010
// octet >> 4;
// temos 0000 0110
// octet << 4;
// temos 1010 0000
// no | (or) fica: (or só torna o bit 1 se um dos dois for 1 naquela posição)
// 1010 0110 que é o swap de 0110 1010