#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*_find_caracter(char *str, int caracter)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)caracter)
			return (&str[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	char str1[] = "breno";
	int character;

	character = 'n';
	printf("find the character %c -->%s\n", character, _find_caracter(str1,
			character));
	return (0);
}