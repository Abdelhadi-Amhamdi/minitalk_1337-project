/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:20:40 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/11/04 16:57:09 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libc.h"

void	ft_putstr(char *str, int *sum);
int		ft_printf(const char *string, ...);
void	ft_putchar(char c, int *sum);
void	ft_putnbr(int n, int *sum);
void	ft_putnbr_hexa(unsigned long nb, char t, int *sum);
void	ft_putchar_hexa(unsigned long nb, char t, int *sum);
void	ft_put_unsigned(unsigned int nb, int *sum);

#endif