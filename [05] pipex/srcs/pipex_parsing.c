/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:45:15 by bportell          #+#    #+#             */
/*   Updated: 2025/06/03 16:12:41 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// função para retornar char **cmd (array de strings com o conteudo do cmd)

// check
// função para contar a quantidade de termos dentro do cmd original
// para dps alocar o array de strings

// check
// função para contar o tamanho de cada parte do cmd (cada palavra)

// função para alocar uma string dentro do array

/**
 * Count the number of parameters in a command string.
 *
 * This function analyzes the command string and returns the
 * number of parameters it contains. It considers text enclosed
 * in a single (' ') or double (" ") quotes as a single paremeter.
 * Even it contains spaces.
 *
 * @param cmd Command String to analyze.
 *
 * @return The number of parameters in the string.
 *         Returns 0 if the string is empty or NULL;
 */
static int	param_number(const char *cmd)
{
	int		count;
	char	quote;

	if (!cmd)
		return (0);
	count = 0;
	while (*cmd)
	{
		while (*cmd == ' ' && *cmd)
			cmd++;
		if (*cmd)
			count++;
		if (*cmd == '\'' || *cmd == '\"')
		{
			quote = *cmd++;
			while (*cmd != quote && *cmd)
				cmd++;
			if (*cmd == quote)
				cmd++;
		}
		while (*cmd != ' ' && *cmd)
			cmd++;
	}
	return (count);
}

/**
 * Count the number of characters of one parameter.
 *
 * This function returns the lenght of one parameter.
 * The parameter is a substring delimited by the char (c).
 * It considers parameters enclosed in a single (' ') or double (" ") quotes,
 * including the quotes themselves.
 *
 * @param str The string where the parameter starts.
 * @param c The delimiter char.
 *
 * @return The number of characters of the parameter including quotes (if any).
 */
static int	param_len(const char *str, char c)
{
	int		len;
	char	quote;

	len = 0;
	if (str[len] == '\'' || str[len] == '\"')
	{
		quote = str[len++];
		while (str[len] != quote && str[len])
			len++;
		if (str[len] == quote)
			len++;
	}
	else
	{
		while (str[len] != c && str[len])
			len++;
	}
	return (len);
}

// int	main(int argc, char **argv)
// {
// 	int			num;
// 	int			len;
// 	const char	*ptr;

// 	if (argc < 2)
// 	{
// 		printf("Usage: %s \"command string\"\n", argv[0]);
// 		return (1);
// 	}

// 	ptr = argv[1];
// 	num = param_number(ptr);
// 	printf("Number of parameters: %d\n", num);

// 	while (num > 0 && *ptr)
// 	{
// 		while (*ptr == ' ')
// 			ptr++;
// 		len = param_len(ptr, ' ');
// 		printf("Length of parameter: %d, parameter: \"", len);
// 		for (int i = 0; i < len; i++)
// 			putchar(ptr[i]);
// 		printf("\"\n");
// 		ptr += len;
// 		num--;
// 	}
// 	return (0);
// }