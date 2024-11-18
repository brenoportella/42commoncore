/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:50:30 by bportell          #+#    #+#             */
/*   Updated: 2024/11/11 13:05:14 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if ((size != 0 && nmemb != 0) && nmemb > SIZE_MAX / size)
		return (0);
	array = malloc(nmemb * size);
	if (!array)
		return (0);
	ft_memset(array, 0, nmemb * size);
	return (array);
}
