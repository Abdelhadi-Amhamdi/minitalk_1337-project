/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:17:38 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/29 10:48:39 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	send_char(char c, int server_id, int interval)
{
	int	bits;

	bits = 8;
	while (bits--)
	{
		if (c & 128)
			kill(server_id, SIGUSR1);
		else
			kill(server_id, SIGUSR2);
		c <<= 1;
		usleep(interval);
	}
}

char	*check_valid_pid(char *pid)
{
	int	index;

	index = 0 ;
	while (pid[index])
	{
		if (!ft_isdigit(pid[index]))
			return (0);
	}
	return (pid);
}

int	main(int ac, char **av)
{
	char	*data;
	int		server_id;
	int		interval;

	interval = 100;
	if (ac == 3)
	{
		data = av[2];
		server_id = ft_atoi(av[1]);
		if (server_id < 1)
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		while (*data)
		{
			send_char(*data, server_id, interval);
			data++;
			if (interval < 1000)
				interval++;
		}
	}
	return (0);
}
