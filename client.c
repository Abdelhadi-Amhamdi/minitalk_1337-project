/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:17:19 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/12/18 21:17:19 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

int i = 0;
int len ;

void	send_char(char c, int id)
{
	int	bits;

	bits = 8;
	while (bits--)
	{
		if (c & 128)
			kill(id, SIGUSR1);
		else
			kill(id, SIGUSR2);
		c <<= 1;
		pause();
		usleep(10);
	}
}

void signal_handler(int sig)
{
	i++;
	if(i == len * 8)
	{
		printf("message delevried !!!\n");
		exit(0);
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		char *data = av[2];
		int server_id = atoi(av[1]);
		len = strlen(data);
		int index = 0;

		signal(SIGUSR2, signal_handler);
		while (data[index])
		{
			send_char(data[index], server_id);
			index++;
		}
		send_char(0, server_id);
	}
	return 0;
}