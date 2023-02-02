/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:31:17 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/02 09:35:19 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_BONUS_H
# define MINI_TALK_BONUS_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

size_t	ft_strlen(const char *tab);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *s);
void	ft_putendl_fd(char *s, int fd);
int		ft_isdigit(int c);
void	ft_putnbr_fd(int x, int fd);
void	*ft_memset(void *dest, int ch, size_t count);
void	*ft_calloc(size_t count, size_t size);

#endif