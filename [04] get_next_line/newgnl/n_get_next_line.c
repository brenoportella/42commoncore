/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_get_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:24:21 by bportell          #+#    #+#             */
/*   Updated: 2025/01/20 16:50:43 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
}

char	*_strjoin(char *str1, char *str2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!str1)
		str1 = "";
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
// uma variavel estatica para armazenar o conteudo
// depois despeja-lo em outra para preencher o que chamaremos de LINHA
// a linha é o que deve ser retornado
// depois vamos reorganizar os dados da variavel estatica, e zeraremos os
// dados que estão dentro dela que já foram utilizados na linha, ficando apenas
// aquilo que nós ainda não retornamos
// portanto vou precisar de uma função de **rearranjar e limpar os dados** dessa
// variavel. considerando que ela é estatica e ja vai ter dados, é importante
// que a atribuição de novos valores nela seja por um **join**, sem apagar
// o conteudo da variavel anterior.
// acontece que vamos ter que saber o que faz parte dessa linha e o que não.
// pra isso temos de **percorrer toda a variavel a procura de um \n** e
// retornar a posição dela.
// vou precisar saber o tamanho dos dados que estão antes da linha (\n) para
// depois saber quantos dados serão movidos e quantos dados serão transformados
// em vazios (\0) qnd rearranjar e limpar os dados

// um dos problemas que tenho aqui é lidar com o buffersize, não é só fazer um
// split de uma string com \n, porque temos de respeitar o tamanho do fetch
// para evitar crashings de memoria, basicamente.
// sendo assim, o tamanho de cada linha é diferente, podendo umas terem 40 bytes
// e outras 1000. sendo assim a variavel line precisa ser incrementada confome
// o tamanho dela aumenta. uma forma de resolver isso é fazer um **join** dela
// com a outra parte que esta sendo lida, limpar a memoria dela e retornar um
// novo pointer para a nova variavel (que possui o antigo e o novo conteudo)
// não pode deixar de limpar o input inicial
// em alguns momentos eu vou ter de lidar com inputs nulos, portanto é
// importante saber lidar com eles.
// por fim, tenho que tomar cuidado com problemas como o read = 0,
ou o fd	ser = 0,
		as coisas precisam existir.
		// confesso que as condiçoes de qnd executar e qnd não ainda estão confusas pra
		// mim,
		então vou tentar ler mais codigo de outras pessoas e entender o que
		// elas lidam.
