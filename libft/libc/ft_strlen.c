/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:48:03 by bportell          #+#    #+#             */
/*   Updated: 2024/11/11 09:48:29 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *str);

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != "\0")
	{
		i++;
	}
	return (i);
}
