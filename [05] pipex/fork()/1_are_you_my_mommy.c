#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int	main(void)
{
	pid_t pid;

	pid = fork(); //a partir daqui o codigo vai ser executado 2 vezes, a variavel pid no processo pai será o PID do filho. no processo filho será 0.
	if (pid < 0)
		printf("erro ao criar o processo filho\n");
	else if (pid == 0)
		printf("FILHO\nPID:%d\nPPID:%d\n", getpid(), getppid());
	else if (pid > 0)
		printf("PAI\nPID:%d\nCPID:%d\n\n", getpid(), pid);
	return (0);
}
