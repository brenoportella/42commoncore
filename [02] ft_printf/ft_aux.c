/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:23:24 by bportell          #+#    #+#             */
/*   Updated: 2024/11/20 14:15:25 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstr(char *str);

static void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

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
	ft_putstr(&str[count]);
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
	if (n > len)
		count += ft_printnbase(n / len, base, len);
	write(1, &base[n % len], 1);
	count++;
	return (count);
}

int	ft_printptr(unsigned long p)
{
	if (!p)
		return (ft_printf("(nil)"));
	ft_printf("0x");
	return (ft_printnbase(p, "0123456789abcdef", 16));
}