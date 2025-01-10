/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:51:29 by bportell          #+#    #+#             */
/*   Updated: 2025/01/10 16:33:42 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 42

int	main(void)
{
	char	*buffer;
	int		my_file;
	ssize_t bytes_read;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (-1);
	my_file = open("ascii-art.txt", O_RDONLY);
	if (my_file == -1)
		return (-1);
	if (bytes_read == -1)
		return (-1);
	while((bytes_read = read(my_file, buffer, BUFFER_SIZE)) > 0)
	{
		// write(1, "linha->\n", 9);
		write(1, buffer, bytes_read);
	}
	
	close(my_file);
	free(buffer);
	return 0;
}
