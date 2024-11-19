/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:04:48 by bportell          #+#    #+#             */
/*   Updated: 2024/11/19 18:37:21 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//my compile command is:  ccf ft_aux.c ft_printf.c -Llibft -lft 
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
			count += ft_pct_found(++str, args);
		else
		{
			write(1, &*str, 1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}
int	ft_pct_found(const char *a_pct, va_list args)
{
	int	count;

	if (*a_pct == '%')
		count = ft_printchar('%');
	if (*a_pct == 'c')
		count = ft_printchar(va_arg(args, int));
	if (*a_pct == 's')
		count = ft_printstr(va_arg(args, char *));
	if (*a_pct == 'd' || *a_pct == 'i')
		count = ft_printnbase(va_arg(args, int), "0123456789", 10);
	return (count);
}

int	main(void)
{
	char	letter;
	char	*string;
	int		number;

	string = "my name is breno";
	letter = 'a';
	number = 95;
	ft_printf("Try to print the letter: %c", letter);
	ft_printf("\n\nTry to print the string: %s", string);
	ft_printf("\n\nTry to print %%");
	ft_printf("\n\nTry to print the number (i || d): %i", number);
	return (0);
}