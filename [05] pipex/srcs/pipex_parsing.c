/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:45:15 by bportell          #+#    #+#             */
/*   Updated: 2025/06/17 18:35:42 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <stdio.h>
// check
// função para contar a quantidade de termos dentro do cmd original
// para dps alocar o array de strings

// check
// função para contar o tamanho de cada parte do cmd (cada palavra)

//check
// função para alocar uma string dentro do array

// função para retornar char **cmd (array de strings com o conteudo do cmd)

/**
 * Allocates and copies a string into a specified position of a string array.
 *
 * This function receives a string array (array of char pointers), a position,
 * and a source string. It allocates enough memory to store the source string
 * (including the * null terminator) and copies the content of the source
 * string into the specified position of the array.
 *
 * @param arr The array of strings (char **), where the string will be stored.
 * @param pos The index in the array where the string will be allocated
 * and copied.
 * @param str The source string to be copied into the array.
 *
 * @return void
 *
 * @note If arr is NULL or the memory allocation fails,
	the function does nothing.
 */
static void	put_str_in_array(char **arr, int pos, const char *str)
{
	int	lenstr;

	if (!arr)
		return ;
	lenstr = ft_strlen(str);
	arr[pos] = malloc((lenstr + 1) * sizeof(char));
	if (!arr[pos])
		return ;
	ft_strlcpy(arr[pos], str, lenstr + 1);
	return ;
}

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
