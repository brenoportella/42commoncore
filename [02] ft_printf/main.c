/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:43:49 by bportell          #+#    #+#             */
/*   Updated: 2025/01/29 21:22:59 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* int	main(void)
{
	char letter;
	char *string;
	char *str = NULL;
	int	*ptr;
	int number;
	int count1;
	int count2;
	int count3;
	int count4;
	int count7;
	int count8;
	int count9;
	int count10;
	int count11;

	ptr = NULL;
	string = "my name is breno";
	letter = 'a';
	number = -95;
	ft_printf("\n_____________FT_PRINTF_____________\n");
	count1 = ft_printf("1 | Try to print the letter: %c", letter);
	count2 = ft_printf("\n2 | Try to print the string: %s", string);
	count3 = ft_printf("\n3 | Try to print the number (i): %i", number);
	count3 = ft_printf("\n3 | Try to print the number (d): %d", number);
	count4 = ft_printf("\n4 | Try to print the unsigned number: %u", number);
	int count5 = ft_printf("\n5 | Try to print the hex lower number (x): %x",
			number);
	int count6 = ft_printf("\n6 | Try to print the hex UPPER number (X): %X",
			number);
	count7 = ft_printf("\n7 | Try to print the pointer: %p", &string);
	count8 = ft_printf("\n8 | Try to print null str: %s", str);
	count9 = ft_printf("\n9 | Try to print %%");
	count10 = ft_printf("\n10 | %s", str);
	count11 = ft_printf("\n11 | %p", ptr);
	ft_printf(NULL);
	printf("\n count1: %i", count1);
	printf("\n count2: %i", count2);
	printf("\n count3: %i", count3);
	printf("\n count4: %i", count4);
	printf("\n count5: %i", count5);
	printf("\n count6: %i", count6);
	printf("\n count7: %i", count7);
	printf("\n count8: %i", count8);
	printf("\n count9: %i", count9);
	printf("\n count10: %i", count10);
	printf("\n count11: %i", count11);
	printf("\n_______________PRINTF______________\n");
	count1 = printf("1 | Try to print the letter: %c", letter);
	count2 = printf("\n2 | Try to print the string: %s", string);
	count3 = printf("\n3 | Try to print the number (i): %i", number);
	count3 = printf("\n3 | Try to print the number (d): %d", number);
	count4 = printf("\n4 | Try to print the unsigned number: %u", number);
	count5 = printf("\n5 | Try to print the hex lower number (x): %x", number);
	count6 = printf("\n6 | Try to print the hex UPPER number (X): %X", number);
	count7 = printf("\n7 | Try to print the pointer: %p", &string);
	count8 = printf("\n8 | Try to print null str: %s", str);
	count9 = printf("\n9 | Try to print %%");
	count10 = printf("\n10 | %s", str);
	count11 = printf("\n11 | %p", ptr);
	printf(NULL);
	printf("\n count1: %i", count1);
	printf("\n count2: %i", count2);
	printf("\n count3: %i", count3);
	printf("\n count4: %i", count4);
	printf("\n count5: %i", count5);
	printf("\n count6: %i", count6);
	printf("\n count7: %i", count7);
	printf("\n count8: %i", count8);
	printf("\n count9: %i", count9);
	printf("\n count10: %i", count10);
	printf("\n count11: %i", count11);
	printf("\n\nend");
	return (0);
} */

int	main(void)
{
	ft_printf("%u\n", __LONG_MAX__);
	printf("%u\n", __LONG_MAX__);
	return (0);
}
