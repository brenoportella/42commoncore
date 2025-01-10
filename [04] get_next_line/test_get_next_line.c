/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:51:29 by bportell          #+#    #+#             */
/*   Updated: 2025/01/10 17:01:40 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	char	*buffer;
	ssize_t	r_value;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
	{
		write(1, "Error: It was not possible allocate memory!\n", 45);
		return 0;
	}
	while ((r_value = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		write(1, buffer, r_value);
	}
	return (buffer);
}

int	main(void)
{
	int		fd;
	char	*buff;

	fd = open("texto.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	buff = get_next_line(fd);
	close(fd);
	free(buff);
	return (0);
}
