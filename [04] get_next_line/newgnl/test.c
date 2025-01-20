#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*_strjoin(char *str1, char *str2)
{
	char *new_str;
	int i;
	int j;

	if (!str1)
		str1 = "";
	if (!str2)
		str2 = "";
	new_str = malloc((_strlen(str1) + _strlen(str2) + 1) * sizeof(char));
	if (!new_str)
		return (0);
	i = -1;
	while (str1[++i])
		new_str[i] = str1[i];
	j = -1;
	while (str2[++j])
		new_str[i + j] = str2[j];
	new_str[i + j] = '\0';
	return (new_str);
}

int	main(void)
{
	// char str1[] = "breno";
	char str2[] = " portella";
	char *new_str;
	int i;

	new_str = NULL;
	new_str = _strjoin("oi", NULL);
	if (!new_str)
		return (0);

	char *temp = _strjoin(new_str, str2);
	free(new_str);  // Libera a memória antes de sobrescrever
	new_str = temp;

	new_str = _strjoin(new_str, str2);
	if (!new_str)
		return (0);
	free(temp);
	i = 0;
	while (new_str[i])
	{
		write(1, &new_str[i], 1);
		i++;
	}
	free(new_str);
}