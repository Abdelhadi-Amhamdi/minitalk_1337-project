/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:16:32 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/28 21:38:37 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

size_t	ft_strlen(const char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

static int	check_if_overflow(long prev, long res)
{
	if (res / 10 == prev)
		return (0);
	return (1);
}

static const char	*trim_white_space(const char *s, int *sign)
{
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			*sign = -1;
		s++;
	}
	return (s);
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

int	ft_atoi(const char *s)
{
	int		sign;
	long	result;
	long	prev;

	result = 0;
	sign = 1;
	s = trim_white_space(s, &sign);
	while (*s >= '0' && *s <= '9')
	{
		prev = result;
		result = (result * 10) + (*s - 48);
		if (check_if_overflow(prev, result) == 1)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		s++;
	}
	return (result * sign);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}