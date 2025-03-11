/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:23:24 by bportell          #+#    #+#             */
/*   Updated: 2025/03/11 12:37:19 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (str[count])
		write(1, &str[count++], 1);
	return (count);
}

int	ft_printnbase(long n, char *base, int len)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n >= len)
		count += ft_printnbase(n / len, base, len);
	write(1, &base[n % len], 1);
	count++;
	return (count);
}

int	ft_printptr(unsigned long p)
{
	int	count;

	count = 2;
	if (!p)
		return (ft_printf("(nil)"));
	ft_printf("0x");
	if (p >= 16)
		count += ft_printnbase(p / 16, "0123456789abcdef", 16);
	write(1, &"0123456789abcdef"[p % 16], 1);
	count++;
	return (count);
}
