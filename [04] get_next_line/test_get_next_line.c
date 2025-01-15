/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:51:29 by bportell          #+#    #+#             */
/*   Updated: 2025/01/15 09:56:59 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
