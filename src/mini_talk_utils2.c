/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:54:11 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/29 10:54:58 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}

void	ft_putnbr_fd(int x, int fd)
{
	unsigned int	n;

	n = x;
	if (x < 0)
	{
		ft_putchar_fd('-', fd);
		n = -x;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	else
		ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	size;

	if (s)
	{
		size = ft_strlen(s);
		write(fd, s, size);
	}
}

size_t	ft_strlen(const char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
