/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:23:24 by bportell          #+#    #+#             */
/*   Updated: 2024/11/19 18:28:21 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	ft_putstr_fd(&str[count], 1);
	return (count);
}

int	ft_printnbase(long n, char *base, int len)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
		count++;
	}
	if (n > len)
		count += ft_printnbase(n / len, base, len);
	ft_putchar_fd(base[n % len], 1);
	count++;
	return (count);
}
