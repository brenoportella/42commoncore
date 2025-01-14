/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:04:50 by bportell          #+#    #+#             */
/*   Updated: 2024/11/20 16:02:23 by bportell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *, ...);
int	ft_pct_found(const char *a_pct, va_list args);
int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_printnbase(long n, char *base, int len);
int	ft_printptr(unsigned long p);

#endif