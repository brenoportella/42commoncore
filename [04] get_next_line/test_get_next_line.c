/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:51:29 by bportell          #+#    #+#             */
/*   Updated: 2025/01/10 21:39:02 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 42
//"lorem ipsum iasfiasasfasfijadj -> A"
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	ssize_t		r_val;
	char		*line;
	int			i;

	while ((r_val = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		i = -1;
		while (buffer[++i] != '\n' && !buffer[i])
			;
			//mudar para do libft
		strncpy(line, buffer, i + 1);
		write(1, "aqui temos 43 caracteres\n", 26);
		write(1, buffer, r_val);
		write(1, "\n", 1);
	}
	printf("%s\n", line);
	return (line);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i1;
	size_t	i2;
	char	*str;

	i1 = 0;
	i2 = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	while (s1[i1])
	{
		str[i1] = s1[i1];
		i1++;
	}
	while (s2[i2])
	{
		str[i1 + i2] = s2[i2];
		i2++;
	}
	str[i1 + i2] = 0;
	return (str);
}

int	main(void)
{
	int		fd;
	char	*buff;

	fd = open("texto.txt", O_RDONLY);
	printf("%d\n", fd);
	if (fd == -1)
		return (-1);
	buff = get_next_line(fd);
	close(fd);
	free(buff);
	return (0);
}
