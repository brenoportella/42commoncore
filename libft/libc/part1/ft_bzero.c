/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:36:13 by bportell          #+#    #+#             */
/*   Updated: 2024/10/28 19:37:51 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_bzero(void *s, unsigned int n);

void    ft_bzero(void *s, unsigned int n)
{
    unsigned char *ptr;
    unsigned int i;

    if (s == 0 || n <= 0)
    return;

    ptr = (unsigned char *)s; //converting the generic pointer to unsigned char
    i = 0;

    while(i < n)
    {
        ptr[i] = 0;
        i++;
    }

}
/*
#include <stdio.h>
#include <strings.h>
int main(void)
{
    char str[] = "breno";
    printf("%s \n", str);
    ft_bzero(str, 3);
    printf("%s \n", str);

}
*/