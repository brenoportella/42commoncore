/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_get_next_line_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:24:16 by bportell          #+#    #+#             */
/*   Updated: 2025/01/20 17:22:50 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_get_next_line.h"

int	_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*_strjoin(char *str1, char *str2)
{
	char *new_str;
	int i;
	int j;

	if (!str1)
		str1 = "";
	if (!str2)
		str2 = "";
	new_str = malloc((_strlen(str1) + _strlen(str2) + 1) * sizeof(char));
	if (!new_str)
		return (0);
	i = -1;
	while (str1[++i])
		new_str[i] = str1[i];
	j = -1;
	while (str2[++j])
		new_str[i + j] = str2[j];
	new_str[i + j] = '\0';
	return (new_str);
}
