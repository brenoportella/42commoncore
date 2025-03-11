#include "../inc/pipex.h"

void	command_one(int pfd[], char *argv[])
{
	char *cmd1[2];

	close(pfd[0]);
	dup2(pfd[1], STDOUT_FILENO);
	close(pfd[1]);
	cmd1[0] = argv[1];
	cmd1[1] = NULL;
	execvp(cmd1[0], cmd1);
	perror("execvp cmd1");
	exit(1);
}

void	command_two(int pfd[], char *argv[])
{
	char *cmd2[2];
	int fd_out;
	
	close(pfd[1]);
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[0]);
	cmd2[0] = argv[2];
	cmd2[1] = NULL;
	fd_out = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		perror("open o_file");
		exit(1);
	}
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	execvp(cmd2[0], cmd2);
	perror("execvp cmd2");
	exit(1);
}
