/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:32:58 by bportell          #+#    #+#             */
/*   Updated: 2024/11/14 15:15:06 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char const *s, char c); //função principal
static int	ft_count_words(char const *s, char c);//conta quantas palavras tem na string
static int	ft_len_word(char const *s, char c);//conta o tamanho da palavra
static char	*ft_put_str(char const *s, int len);//aloca espaço para a string, insere o conteudo usando strlcopy
static char	**ft_create_arrays(int n);//cria um array de arrays
static void	ft_mem_free(char **arrays, int nmb_arrays);//limpa memoria do array inicial até o atual e depois do array de arrays

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**arrays;

	arrays = ft_create_arrays(ft_count_words(s, c));
	if (!s || !arrays)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (ft_len_word(&s[i], c) > 0)
		{
			arrays[j] = ft_put_str(&s[i], ft_len_word(&s[i], c));
			if (!arrays[j])
				ft_mem_free(arrays, j);
			j++;
		}
		i += ft_len_word(&s[i], c);
	}
	return (arrays);
}
static void	ft_mem_free(char **arrays, int nmb_arrays)
{
	int	i;

	i = 0;
	while (i < nmb_arrays)
		free(arrays[i++]);
	free(arrays);
}
static char	*ft_put_str(char const *s, int len)
{
	char	*str;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s, len + 1);
	return (str);
}
static int	ft_len_word(char const *s, char c)
{
	int	len_word;

	len_word = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		len_word++;
		s++;
	}
	return (len_word);
}
static int	ft_count_words(char const *s, char c)
{
	int	nmb_words;

	nmb_words = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			nmb_words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (nmb_words);
}
static char	**ft_create_arrays(int n)
{
	char	**arrays;

	arrays = malloc((n + 1) * sizeof(char *));
	if (!arrays)
		return (0);
	arrays[n] = NULL;
	return (arrays);
}
/*
#include <stdio.h>

int	main(void)
{
	char	**str1;

	str1 = ft_split("   lorem   ipsum dolor     sit amet,
			consectetur   adipiscing elit. Sed non risus. Suspendisse   ",
			' ' );
	while (*str1)
	{
		printf("%s\n", *str1++);
	}
	return (0);
}
*/