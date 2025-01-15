/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:51:32 by bportell          #+#    #+#             */
/*   Updated: 2025/01/15 16:42:34 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

void	*ft_memset(void *s, int c, size_t n);
char	*ft_strjoin(char *s1, char *s2);
void	ft_adjustMemory(char *buffer);
int		ft_newLineExists(char *line);
int		ft_strlen(char *str);
#endif