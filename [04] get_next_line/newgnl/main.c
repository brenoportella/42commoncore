/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:52:45 by bportell          #+#    #+#             */
/*   Updated: 2025/01/23 09:55:10 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("../texto.txt", O_RDONLY);
	i = 1;
	line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%d-->%s\n", i, line);
		i++;
		free(line);
	}
	close(fd);
	return (0);
}
