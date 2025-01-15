/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:51:33 by bportell          #+#    #+#             */
/*   Updated: 2025/01/15 16:51:55 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i1;
	size_t	i2;
	char	*str;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	i1 = -1;
	while (s1[++i1])
		str[i1] = s1[i1];
	i2 = 0;
	if (s2[i2]) // verificar se essa condição pode ser só ignorada em testes dps
		str[i1++] = s2[i2++];
	while (s2[i2] && s2[i2 - 1] != '\n')
		str[i1++] = s2[i2++];
	str[i1] = '\0';
	free(s1);
	return (str);
}
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
void	ft_adjustMemory(char *buffer)
{
	int	newLinePos;
	int	i;
	int	j;

	newLinePos = 0;
	while (buffer[newLinePos] && buffer[newLinePos] != '\n')
		newLinePos++;
	i = newLinePos;
	j = 0;
	if (buffer[i] == '\n')
		while (buffer[++i] && i < BUFFER_SIZE)
			buffer[j++] = buffer[i];
	ft_memset(&buffer[j], '\0', BUFFER_SIZE - j);
}
int	ft_newLineExists(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\n')
			return (1);
	}
	return (0);
}
int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}