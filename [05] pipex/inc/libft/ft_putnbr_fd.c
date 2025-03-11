/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:39:52 by bportell          #+#    #+#             */
/*   Updated: 2024/11/18 14:23:46 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nmb, int fd)
{
	char	c;

	if (nmb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nmb < 0)
	{
		write(fd, "-", 1);
		nmb = -nmb;
	}
	if (nmb > 9)
		ft_putnbr_fd(nmb / 10, fd);
	c = '0' + (nmb % 10);
	write(fd, &c, 1);
}
