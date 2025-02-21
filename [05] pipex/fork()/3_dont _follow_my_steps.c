#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int pid = fork();

	if (pid < 0)
		printf("erro ao criar processo filho\n");
	else if (pid == 0) { // No processo filho
		printf("Executando ls no filho...\n");
		execl("/bin/ls", "ls", "-l", NULL);  // Substitui o processo filho por 'ls -l'
		// O código abaixo não será executado se execl for bem-sucedido
		perror("execl falhou");
	} else { // No processo pai
		wait(NULL);  // Espera o filho terminar
		printf("O processo pai terminou\n");
	}
	
	return 0;
}
