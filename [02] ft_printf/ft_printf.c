/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:04:48 by bportell          #+#    #+#             */
/*   Updated: 2024/11/20 15:01:29 by bportell         ###   ########.fr       */
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

int	main(void)
{
	char	letter;
	char	*string;
	int		number;
	int		count1;
	int		count2;
	int		count3;
	int		count4;
	int		count5;
	int		count6;
	int		count7;
	int		count8;

	string = "my name is breno";
	letter = 'a';
	number = 95;
	ft_printf("_____________FT_PRINTF_____________\n");
	count1 = ft_printf("1 | Try to print the letter: %c", letter);
	count2 = ft_printf("\n2 | Try to print the string: %s", string);
	count3 = ft_printf("\n3 | Try to print the number (i || d): %i", number);
	count4 = ft_printf("\n4 | Try to print the unsigned number: %u", number);
	count5 = ft_printf("\n5 | Try to print the hex lower number (x): %x",
			number);
	count6 = ft_printf("\n6 | Try to print the hex UPPER number (X): %X",
			number);
	count7 = ft_printf("\n7 | Try to print the pointer: %p", &string);
	count8 = ft_printf("\n8 | Try to print %%");
	printf("\n\n count1: %i", count1);
	printf("\n count2: %i", count2);
	printf("\n count3: %i", count3);
	printf("\n count4: %i", count4);
	printf("\n count5: %i", count5);
	printf("\n count6: %i", count6);
	printf("\n count7: %i", count7);
	printf("\n count8: %i", count8);
	printf("\n_______________PRINTF______________\n");
	count1 = printf("1 | Try to print the letter: %c", letter);
	count2 = printf("\n2 | Try to print the string: %s", string);
	count3 = printf("\n3 | Try to print the number (i || d): %i", number);
	count4 = printf("\n4 | Try to print the unsigned number: %u", number);
	count5 = printf("\n5 | Try to print the hex lower number (x): %x", number);
	count6 = printf("\n6 | Try to print the hex UPPER number (X): %X", number);
	count7 = printf("\n7 | Try to print the pointer: %p", &string);
	count8 = printf("\n8 | Try to print %%");
	printf("\n\n count1: %i", count1);
	printf("\n count2: %i", count2);
	printf("\n count3: %i", count3);
	printf("\n count4: %i", count4);
	printf("\n count5: %i", count5);
	printf("\n count6: %i", count6);
	printf("\n count7: %i", count7);
	printf("\n count8: %i", count8);
	printf("\n\nend");
	return (0);
}
