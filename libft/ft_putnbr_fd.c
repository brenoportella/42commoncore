/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:39:52 by bportell          #+#    #+#             */
/*   Updated: 2024/11/15 12:58:06 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nmb, int fd)
{
	char	c;

	if (nmb == -2147483648) //lidar com o menor int
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nmb < 0) //se for negativo, printar '-' e transformar em positivo
	{
		write(fd, "-", 1);
		nmb = -nmb;
	}
	if (nmb > 9) //enquanto o nmb for maior que 9, recursiva do nmb / 10, para fazer para cada unidade (centena dezena etc)
		ft_putnbr_fd(nmb / 10, fd);
	c = '0' + (nmb % 10); //qnd o nmb for 9 ou menos, é o resultado da divisão dele por 10, que é literalmente ele
	write(fd, &c, 1); //ai escreve só ele no final e pronto
}
