/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:04:48 by bportell          #+#    #+#             */
/*   Updated: 2024/11/20 14:21:05 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (*a_pct == 'c')
		count = ft_printchar(va_arg(args, int));
	else if (*a_pct == 's')
		count = ft_printstr(va_arg(args, char *));
	else if (*a_pct == 'p')
		count = ft_printptr(va_arg(args, unsigned long));
	else if (*a_pct == 'd' || *a_pct == 'i')
		count = ft_printnbase(va_arg(args, int), "0123456789", 10);
	else if (*a_pct == 'u')
		count = ft_printnbase(va_arg(args, unsigned int), "0123456789", 10);
	else if (*a_pct == 'x')
		count = ft_printnbase(va_arg(args, int), "0123456789abcdef", 16);
	else if (*a_pct == 'X')
		count = ft_printnbase(va_arg(args, int), "0123456789ABCDEF", 16);
	else
		count = ft_printchar(*a_pct);
	return (count);
}

/*
int	main(void)
{
	char letter;
	char *string;
	int number;

	string = "my name is breno";
	letter = 'a';
	number = 95;
	ft_printf("Try to print the letter: %c", letter);
	ft_printf("\nTry to print the string: %s", string);
	ft_printf("\nTry to print the number (i || d): %i", number);
	ft_printf("\nTry to print the unsigned number: %u", number);
	ft_printf("\nTry to print the hex lower number (x): %x", number);
	ft_printf("\nTry to print the hex UPPER number (X): %X", number);
	ft_printf("\nTry to print the pointer: %p", &string);
	ft_printf("\nTry to print %%");
	printf("\n\nPrintf the letter: %c", letter);
	printf("\nPrintf the string: %s", string);
	printf("\nPrintf the number (i || d): %i", number);
	printf("\nPrintf the unsigned number: %u", number);
	printf("\nPrintf lower HEX: %x", number);
	printf("\nPrintf UPPER HEX: %X", number);
	printf("\nPrintf the pointer: %p", &string);
	printf("\nPrintf to print %%");
	printf("\n\nend");
	return (0);
}
*/