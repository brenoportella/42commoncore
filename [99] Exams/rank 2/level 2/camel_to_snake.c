/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:54:17 by bportell          #+#    #+#             */
/*   Updated: 2025/05/16 18:40:41 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
*/

#include <stdlib.h>
#include <unistd.h>

int	_is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}
int	_uppercount(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (_is_uppercase(str[i]))
			result++;
		i++;
	}
	return (result);
}
int	_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return ;
}
char	*camel_to_snake(char *camel)
{
	char	*snake;
	int		i;
	int		j;
	int		size_snake;

	size_snake = _strlen(camel) + _uppercount(camel) + 1;
	snake = malloc(size_snake * sizeof(char));
	if (!snake)
		return (NULL);
	i = 0;
	j = 0;
	while (camel[i])
	{
		if (_is_uppercase(camel[i]))
		{
		}
		if (_is_uppercase(camel[i]))
		{
		}
		else if (!_is_uppercase(camel[i]))
		{
		}
		++;
	}
	return (snake);
}

#include <stdio.h>

int	main(void)
{
	char camel[] = "minhaCamelString";
	printf("%s\n", camel_to_snake(camel));
	return (0);
}