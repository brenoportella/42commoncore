/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:27:00 by bportell          #+#    #+#             */
/*   Updated: 2025/05/29 12:30:13 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : flood_fill
Expected files   : *.c, *.h
Allowed functions: -
--------------------------------------------------------------------------------

Write a function that takes a char ** as a 2-dimensional array of char, a
t_point as the dimensions of this array and a t_point as the starting point.

Starting from the given 'begin' t_point, this function fills an entire zone
by replacing characters inside with the character 'F'. A zone is an group of
the same character delimitated horizontally and vertically by other characters
or the array boundry.

The flood_fill function won't fill diagonally.

The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);

The t_point structure is prototyped like this:

  typedef struct  s_point
  {
	int		x;
	int		y;
  }               t_point;

Example:

$> cat test.c
#include "flood_fill.h"
#include <stdio.h>
#include <stdlib.h>

char** make_area(char** zone, t_point size)
{
	char** new;
	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}
	return (new);
}

int	main(void)
{
	t_point	size;
	t_point	begin;

	size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};
	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");
	begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

$> gcc flood_fill.c test.c -o test; ./test
11111111
10001001
10010001
10110001
11100001

FFFFFFFF
F000F00F
F00F000F
F0FF000F
FFF0000F
$>
*/
typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

// Função recursiva auxiliar que faz o preenchimento
void	fill(char **tab, t_point size, int x, int y, char target)
{
	// Verifica se está fora dos limites
	if (x < 0 || x >= size.x || y < 0 || y >= size.y)
		return ;
	// Se o caractere atual não é igual ao que queremos substituir, não faz nada
	if (tab[y][x] != target)
		return ;
	// Marca a célula com 'F'
	tab[y][x] = 'F';
	// Chama recursivamente nas 4 direções
	fill(tab, size, x + 1, y, target); // direita
	fill(tab, size, x - 1, y, target); // esquerda
	fill(tab, size, x, y + 1, target); // baixo
	fill(tab, size, x, y - 1, target); // cima
}

// Função principal que é chamada pelo usuário
void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;

	// Guarda o caractere original da posição inicial
	target = tab[begin.y][begin.x];
	// Inicia o preenchimento
	if (target != 'F') // evita sobrescrever se já estiver preenchido
		fill(tab, size, begin.x, begin.y, target);
}
#include <stdlib.h>
#include <stdio.h>

// Copia a zona original para um novo array dinâmico
char **make_area(char **zone, t_point size)
{
	char **new = malloc(sizeof(char *) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0'; // null-terminar cada linha
	}
	return new;
}

// Mostra o mapa na tela
void print_area(char **area, t_point size)
{
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
}

int main(void)
{
	t_point size = {8, 5}; // largura = 8, altura = 5
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001"
	};

	char **area = make_area(zone, size);

	printf("Original:\n");
	print_area(area, size);

	t_point begin = {7, 4}; // ponto de partida para o flood fill
	flood_fill(area, size, begin);

	printf("\nAfter flood_fill:\n");
	print_area(area, size);

	// Liberação de memória
	for (int i = 0; i < size.y; ++i)
		free(area[i]);
	free(area);

	return 0;
}
