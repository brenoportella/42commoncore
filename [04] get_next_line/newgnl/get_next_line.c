/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:24:21 by bportell          #+#    #+#             */
/*   Updated: 2025/01/23 09:51:26 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*maybe rewrite this function or study and comment it a lot*/
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		readBytes;

	if (BUFFER_SIZE <= 0 || fd <= 0)
		return (_memalign(buffer), NULL);
	line = _strjoin(NULL, buffer);
	if (!line)
		return (NULL);
	_memalign(buffer);
	readBytes = 1;
	while (!(_find_caracter(line)))
	{
		readBytes = read(fd, buffer, BUFFER_SIZE);
		if (readBytes <= 0)
			break ;
		line = _strjoin(line, buffer);
		if (!line)
			return (NULL);
		_memalign(buffer);
	}
	if (!line[0] || readBytes < 0)
		return (free(line), NULL);
	return (line);
}
