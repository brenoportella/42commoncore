#ifndef PIPEX_H
# define PIPEX_H

// LIBS
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// AUX
void	command_one(int pfd[], char *argv[], char *envp[]);
void	command_two(int pfd[], char *argv[], char *envp[]);
char	*get_cmd_path(char *cmd, char **envp);
void	free_split(char **split);

#endif