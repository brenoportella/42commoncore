#include "n_get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		readBytes;

	if (BUFFER_SIZE <= 0 || fd <= 0)
		return (_memalign(buffer), NULL);
	line = _strjoin(NULL, buffer); //se o buffer não tiver nada, isso aqui é só a inicializaçao da variavel
	if (!line)
		return (NULL);
	_memalign(buffer); //se o buffer for vazio? vai retornar ele vazio na mesma
	readBytes = 1;
	while (!(_find_caracter(line))) //se o \n não for encontrado na line (que esta vazia)
	{
		readBytes = read(fd, buffer, BUFFER_SIZE);
		if (readBytes <= 0)
			break;
		line = _strjoin(line, buffer); //vai pegar a line vazia e atribuir o que tava dentro de buffer nela, o problema que tudo ta dentro de buffer.
		if (!line)
			return (NULL);
		_memalign(buffer);//vai organizar o buffer pra dps da primeira \n
	}
	if (!line[0] || readBytes < 0)
		return (free(line), NULL);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("breno.txt", O_RDONLY);
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
