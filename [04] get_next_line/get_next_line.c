/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:51:31 by bportell          #+#    #+#             */
/*   Updated: 2025/01/15 17:02:34 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		readSize;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (ft_memset(buffer, '0', BUFFER_SIZE));
	line = ft_strjoin(NULL, buffer);
	if (!line)
		return (NULL);
	ft_adjustMemory(buffer);
	readSize = 1;
	while (!(ft_newLineExists(line)))
	{
		readSize = read(fd, buffer, BUFFER_SIZE);
		if (readSize <= 0)
			break ;
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		ft_adjustMemory(buffer);
	}
	if (!line[0] || readSize < 0)
		return (free(line), NULL);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("ascii-art.txt", O_RDONLY);
	i = 1;
	line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("the line Nº%d is: %s", i, line);
		i++;
		free(line);
	}
	close(fd);
	return (0);
}
