#include <stdio.h>

// função para retornar char **cmd (array de strings com o conteudo do cmd)

//check
// função para contar a quantidade de termos dentro do cmd original para dps alocar o array de strings


// função para contar o tamanho de cada parte do cmd (cada palavra)


// função para alocar uma string dentro do array

/**
 * Count the number of parameters in a command string.
 *
 * This function analyzes the command string and returns the
 * number of parameters it contains. It considers text enclosed
 * in a single (' ') or double (" ") quotes as a single paremeter.
 * Even it contains spaces.
 *
 * @param cmd Command String to analyze.
 *
 * @return The number of parameters in the string.
 *         Returns 0 if the string is empty or NULL;
 */
static int	param_number(const char *cmd)
{
	int		count;
	char	quote;

	if (!cmd)
		return (0);
	count = 0;
	while (*cmd)
	{
		while (*cmd == ' ' && *cmd)
			cmd++;
		if (*cmd)
			count++;
		if (*cmd == '\'' || *cmd == '\"')
		{
			quote = *cmd++;
			while (*cmd != quote && *cmd)
				cmd++;
			if (*cmd == quote)
				cmd++;
		}
		while (*cmd != ' ' && *cmd)
			cmd++;
	}
	return (count);
}

// static int param_len(const char *str)
// {

// }


int	main(int argc, char **argv)
{
	int num;
	(void)argc;
	num = param_number(argv[1]);
	printf("%i\n", num);
	if (argv[1])
		printf("%s\n", argv[1]);
}