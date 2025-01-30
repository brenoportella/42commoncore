/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:24:21 by bportell          #+#    #+#             */
/*   Updated: 2025/01/30 13:32:46 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		read_bytes;

	if (BUFFER_SIZE <= 0 || fd <= 0)
		return (_memalign(buffer), NULL);
	line = _strjoin(NULL, buffer);
	if (!line)
		return (NULL);
	_memalign(buffer);
	read_bytes = 1;
	while (!(_find_caracter(line)))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		line = _strjoin(line, buffer);
		if (!line)
			return (NULL);
		_memalign(buffer);
	}
	if (!line[0] || read_bytes < 0)
		return (free(line), NULL);
	return (line);
}
