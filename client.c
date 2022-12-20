/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:17:38 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/12/20 19:21:54 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void	send_char(char c, int server_id, int buffer_length)
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
		usleep(300);
	}
}

void	signal_handler(int signal_type)
{
	if (signal_type == SIGUSR2)
		printf("message delevried !!!\n");
}

int	main(int ac, char **av)
{
	char	*data;
	int		server_id;
	int		data_length;

	if (ac == 3)
	{
		data = av[2];
		server_id = atoi(av[1]);
		data_length = strlen(data);
		signal(SIGUSR2, signal_handler);
		while (*data)
		{
			send_char(*data, server_id, (data_length + 1));
			data++;
		}
		send_char(0, server_id, (data_length + 1));
	}
	return (0);
}
