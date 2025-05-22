/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:16:36 by bportell          #+#    #+#             */
/*   Updated: 2025/05/22 15:32:09 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

Examples:
$>./camel_to_snake "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./camel_to_snake "hello_world" | cat -e
helloWorld$
$>./camel_to_snake | cat -e
$
*/
#include <stdlib.h>
#include <unistd.h>

int	_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return ;
}
int	count_snake(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '_')
			res++;
		i++;
	}
	return (res);
}
char	*snake_str(int len)
{
	char	*snake;

	snake = malloc((len + 1) * sizeof(char));
	if (!snake)
		return (NULL);
	return (snake);
}
char	*camel_to_snake(char *str)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	len = _strlen(str) - count_snake(str);
	res = snake_str(len);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '_')
			i++;
		if (str[i - 1] == '_' && str[i])
			res[j++] = str[i] - 32;
		else if (str[i] != '_' && str[i])
			res[j++] = str[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}

int	main(int argc, char **argv)
{
	char *snake;

	if (argc == 2)
	{
		snake = camel_to_snake(argv[1]);
		putstr(snake);
		free(snake);
	}
	write(1, "\n", 1);
	return (0);
}