#include <stdio.h>
#include <stdlib.h>

int	count_tokens(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
        
	}
	return (count);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("ERROR: tem que ter 2 argumentos");
		return (1);
	}
	printf("%i quantidade de termos\n", count_tokens(argv[1], ' '));
	return (0);
}