/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:18:12 by bportell          #+#    #+#             */
/*   Updated: 2025/05/21 12:04:44 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char	*ft_strdup(char *src);
*/

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	if (!src)
		return NULL;
	i = 0;
	while (src[i])
		i++;
	dup = malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	char *dup;
	if (argc != 2)
		return (0);
	dup = ft_strdup(argv[1]);
	printf("original: %s\n", argv[1]);
	printf("dup: %s\n", dup);
	free(dup);
	return (0);
}