/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:36:37 by bportell          #+#    #+#             */
/*   Updated: 2024/10/28 19:37:51 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isdigit(int c);

int ft_isdigit(int c)
{
    if(c >= 48 && c <= 57)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}