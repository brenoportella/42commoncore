/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:51:29 by bportell          #+#    #+#             */
/*   Updated: 2025/01/14 18:56:34 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//"lorem ipsum iasfiasasfasfijadj -> A"
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	ssize_t		r_val;
	char		*line;
	int			i;
	char		*nl_flag;

	line = NULL;
	while ((r_val = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[r_val] = '\0';
		// devemos ver se a linha está completa dentro do buffer (\n).
		nl_flag = ft_strchr(buffer, '\n');
		if (nl_flag != NULL) // se ele encontrou um \n
		{
			i = nl_flag - buffer + 1;
			// criar uma função paralela pra isso
			line = ft_strjoin(line, buffer);
			if (line == NULL)
				return (NULL);
			// ft_strlcpy(line, buffer, i + 1);
			// funçao acaba aqui, retorna a line
			// movendo o conteudo dps do \n para o inicio do buffer,sobrescrevendo o conteudo.
			// explicar esse conteudo
			ft_memmove(buffer, nl_flag + 1, BUFFER_SIZE - i);
			buffer[BUFFER_SIZE - i] = '\0';
			return (line);
		}
		else
		{
			line = ft_strjoin(line, buffer);
			if (line == NULL)
				return NULL;
		}
	}
	if (r_val == 0 && line == NULL)
		return (line);
	return (NULL);
}
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*buff;
	int		i;

	fd = open("texto.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	i = 0;
	while ((buff = get_next_line(fd)) != NULL)
	{
		i++;
		printf("%s", buff);
		printf("LINHA Nº%d -->", i);
		free(buff);
	}
	close(fd);
	return (0);
}
