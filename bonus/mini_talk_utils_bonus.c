/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:16:32 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/30 22:08:06 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
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

int	ft_atoi(const char *s)
{
	int		sign;
	long	result;
	long	prev;

	if (!s)
		return (0);
	result = 0;
	sign = 1;
	s = trim_white_space(s, &sign);
	while (*s >= '0' && *s <= '9')
	{
		prev = result;
		result = (result * 10) + (*s - 48);
		s++;
	}
	return (result * sign);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	p = malloc(size * count);
	if (!p)
		return (0);
	ft_memset(p, 0, (count * size));
	return (p);
}

void	*ft_memset(void *dest, int ch, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((unsigned char *)dest)[i] = (unsigned char)ch;
		i++;
	}
	return (dest);
}
