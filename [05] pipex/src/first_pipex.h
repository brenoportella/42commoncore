#ifndef FIRST_PIPEX_H

# define FIRST_PIPEX_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	command_one(int pfd[], char *argv[]);
void	command_two(int pfd[], char *argv[]);
#endif