/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:54:20 by bportell          #+#    #+#             */
/*   Updated: 2025/05/27 12:26:45 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);

*/
int	get_value_c(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	if (c >= 'a' && c <= 'f')
		return (c - 87);
	if (c >= 'A' && c <= 'F')
		return (c - 55);
	return (-1);
}
int	ft_atoi_base(const char *str, int str_base)
{
	int i;
	int signal;
	int res;
	int real_val;

	i = 0;
	res = 0;
	signal = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal = -signal;
		i++;
	}
	while (str[i])
	{
		real_val = get_value_c(str[i]);
		if (real_val != -1 && real_val < str_base)
		{
			res = res * str_base + real_val;
			i++;
		}
		else
			break;
	}
	return (res * signal);
}

#include <stdio.h>
int main (void)
{
	printf("%i\n", ft_atoi_base("f", 16));
	printf("%i\n", ft_atoi_base("z", 26));
	printf("%i\n", ft_atoi_base("42", 10));
	printf("%i\n", ft_atoi_base("00001010", 2));
}