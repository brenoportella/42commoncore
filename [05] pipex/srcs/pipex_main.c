#include "../inc/pipex.h"

int	main(int argc, char *argv[])
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];

	if (argc != 4)
	{
		write(2, "Usage: ./pipex cmd1 cmd2 file\n", 31);
		return (1);
	}
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid1 = fork();
	if (pid1 == 0)
		command_one(pipefd, argv);
	pid2 = fork();
	if (pid2 == 0)
		command_two(pipefd, argv);
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}
