#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*nl_flag;
	ssize_t		r_val;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		// Ler do arquivo apenas se o buffer estiver vazio
		if (buffer[0] == '\0')
		{
			r_val = read(fd, buffer, BUFFER_SIZE);
			if (r_val <= 0) // EOF ou erro
				break;
			buffer[r_val] = '\0'; // Null-terminator no buffer
		}
		// Procurar '\n' no buffer
		nl_flag = ft_strchr(buffer, '\n');
		if (nl_flag)
		{
			size_t len = nl_flag - buffer + 1;
			line = ft_strjoin(line, buffer); // Adicionar até o '\n'
			if (!line)
				return (NULL);
			ft_memmove(buffer, nl_flag + 1, BUFFER_SIZE - len);
			buffer[BUFFER_SIZE - len] = '\0'; // Limpar o restante do buffer
			return (line); // Linha completa encontrada
		}
		// Se não há '\n', acumular o buffer e limpar
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		buffer[0] = '\0'; // Esvaziar buffer
	}
	return (line); // Retornar última linha no EOF
}

int	main(void)
{
	int		fd;
	char	*buff;
	int		i;

	fd = open("breno.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	i = 0;
	while ((buff = get_next_line(fd)) != NULL)
	{
		i++;
		printf("Linha Nº%d ---->%s<----\n", i, buff);
		free(buff);
	}
	close(fd);
	return (0);
}



