/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   COMMENTED_get_next_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:24:21 by bportell          #+#    #+#             */
/*   Updated: 2025/01/30 13:41:32 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//the function in the first execution
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1]; //000000000000000000
	char		*line;
	ssize_t		readBytes;

	if (BUFFER_SIZE <= 0 || fd <= 0)
		return (_memalign(buffer), NULL);
	line = _strjoin(NULL, buffer);//000000000000000000
	if (!line)
		return (NULL);
	_memalign(buffer);//000000000000000000000000000000000
	readBytes = 1;
	while (!(_find_caracter(line)))//qnd a line tem um \n no conteudo dela, ele então retorna a line e acaba o loop
	{
		readBytes = read(fd, buffer, BUFFER_SIZE);//aqui tem um texto com uma new line\naqui tem o texto depois da new line
		if (readBytes <= 0)
			break ;
		line = _strjoin(line, buffer);//line: aqui tem um texto com uma new line\n 
		if (!line)
			return (NULL);
		_memalign(buffer);//buffer: aqui tem o texto depois da new line000000000000000000
	}
	if (!line[0] || readBytes < 0)
		return (free(line), NULL);
	return (line);//line: aqui tem um texto com uma new line\n 
}
//the function after the first execution
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1]; //buffer: aqui tem o texto depois da new line000000000000000000
	char		*line;
	ssize_t		readBytes;

	if (BUFFER_SIZE <= 0 || fd <= 0)
		return (_memalign(buffer), NULL);
	line = _strjoin(NULL, buffer);//line: aqui tem o texto depois da new line
	if (!line)
		return (NULL);
	_memalign(buffer);//buffer:000000000000000000000000000000000
	readBytes = 1;
	while (!(_find_caracter(line)))//qnd a line tem um \n no conteudo dela, ele então retorna a line e acaba o loop
	{
		readBytes = read(fd, buffer, BUFFER_SIZE);//buffer: aqui tem mais texto com uma nl\n e mais texto depois dela
		if (readBytes <= 0)
			break ;
		line = _strjoin(line, buffer);//line: aqui tem o texto depois da new line aqui tem mais texto com uma nl\n
		if (!line)
			return (NULL);
		_memalign(buffer);// e mais texto depois dela00000000000000000000000
	}
	if (!line[0] || readBytes < 0)
		return (free(line), NULL);
	return (line);//line: aqui tem o texto depois da new line aqui tem mais texto com uma nl\n
}
