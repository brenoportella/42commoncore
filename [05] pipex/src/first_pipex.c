#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int pipefd[2]; // aqui eu to criando um array para o pipe
					// [0] é read e [1] write
	pid_t pid1;
	pid_t pid2;

	if (argc != 4) // verificação da quantidade de argumentos
	{
		write(2, "Usage: ./pipex cmd1 cmd2 file\n", 31);
		return (1);
	}

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}

	pid1 = fork(); // criar filho 1
	if (pid1 == 0) // se for diferente de 0, ou deu erro (-1) ou é pai
	{
		// filho 1 - o primeiro comando
		close(pipefd[0]); // fecha leitura do pipe
		dup2(pipefd[1], STDOUT_FILENO);
		// redirecionando a saida desse comando para o pipe1
		close(pipefd[1]); // fechando a escrita do pipe

		char *arg1[] = {argv[1], NULL}; // copiando o comand 1
		execvp(arg1[0], arg1);
		perror("execvp");
		return (1);
	}

	pid2 = fork(); // criar filho 2
	if (pid2 == 0)
	{
		// filho 2 - segundo comando
		int fd_out;
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);

		char *arg2[] = {argv[2], NULL};
		fd_out = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		execvp(arg2[0], arg2);
		perror("execvp");
		return (1);
	}

	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
	wait(NULL);

	return (0);
}