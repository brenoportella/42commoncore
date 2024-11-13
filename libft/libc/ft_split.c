/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:32:58 by bportell          #+#    #+#             */
/*   Updated: 2024/11/13 17:36:03 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char const *s, char c);
static int	ft_count_words(char const *s, char c);
static int	ft_len_word(char const *s, char c);
static char	*ft_put_str(char const *s, int len);
static char	**ft_create_arrays(int n);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**arrays;

	if (!s || !c)
		return (0);
	arrays = ft_create_arrays(ft_count_words(s, c));
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		arrays[j] = ft_put_str(&s[i], ft_len_word(&s[i], c));
		i += ft_len_word(&s[i], c);
		if (!arrays[j])
		{
			while (j > 0)
				free(arrays[--j]);
			free(arrays);
			return (0);
		}
		j++;
	}
	return (arrays);
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

	str1 = ft_split("dog cat romantic coffee", ' ');
	printf("%s\n", str1[2]);
	return (0);
}
*/