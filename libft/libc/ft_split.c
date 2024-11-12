/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:39:54 by bportell          #+#    #+#             */
/*   Updated: 2024/11/12 17:44:58 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_count(char const *s, char c);
static char	**ft_create_array(int n);
static char	*ft_put_word(char const *array, int len);
static void	*ft_free_array(char **array, int max);
static int	ft_len_word(char const *s, char c);

static int	ft_len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		begin_word;
	int		len_word;
	char	**splited;

	j = 0;
	splited = ft_create_array(ft_str_count(s, c));
	while (*s)
	{
		while (*s == c && *s)
			s++;
		len_word = ft_len_word(s, c);
		splited[j] = ft_put_word(*s, len_word);
		if (!splited[j])
			return (ft_free_array(splited, ft_str_count(s, c) + 1));
		s += len_word;
		j++;
	}
	splited[j] = 0;
	return (splited);
}
static int	ft_str_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}
static char	**ft_create_array(int n)
{
	char	**words_array;

	words_array = malloc((n + 1) * sizeof(char *));
	if (!words_array)
		return (NULL);
	words_array[n] = NULL;
	return (words_array);
}
static char	*ft_put_word(char const *array, int len)
{
	char	*word;

	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, array, len + 1);
	return (word);
}

static void	*ft_free_array(char **array, int max)
{
	int	i;

	i = 0;
	while (i < max)
		free(array[i++]);
	free(array);
	return (NULL);
}
