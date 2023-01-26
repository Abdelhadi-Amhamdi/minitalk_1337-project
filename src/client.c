/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:17:38 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/26 22:21:01 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"
#include "mini_talk.h"

void	send_char(char c, int server_id)
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
		usleep(600);
	}
}

char *check_valid_pid(char *pid)
{
	int index;

	index = 0 ;
	while(pid[index])
	{
		if(!ft_isdigit(pid[index]))
			return (0);
	}
	return (pid);
}


int	main(int ac, char **av)
{
	char	*data;
	int		server_id;

	if (ac == 3)
	{
		data = av[2];
		server_id = ft_atoi(av[1]);
		if(server_id < 1)
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		while (*data)
		{
			send_char(*data, server_id);
			data++;
		}
		send_char(0, server_id);
	}
	return (0);
}
