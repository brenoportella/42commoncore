#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	_memalign(char *buffer)
{
	int	i; //A POSICAO DE \N
	int	j; //O INICIO DO BUFFER ATE ONDE ELE RECEBEU BYTS OU SEJA O TAMANHO DO TEXTO DPS DO /N, ELE MENOS O BUFFER É O TOTAL DE NULOS

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		j = 0;
		while(buffer[i] && i < 42)
			buffer[j++] = buffer[i++];
	}
	//até aqui nós só trocamos os bytes de lugar.
	while ((42 - j))
	return ;
}

int	main(void)
{
	char a[] = "Breno Portella"; // src
	// char b[20] = {0};            // dest
	printf("BEFORE FT_MEMMOVE:\nThe src array is: %s\nThe dest array is: %s\n",
		a, a);
	_memalign(a, a + 6, 5);
	printf("AFTER FT_MEMMOVE\nThe src array is: %s\nThe dest array is: %s\n", a,
		a);
	return (0);
}