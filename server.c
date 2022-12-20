/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:57:57 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/12/20 19:15:15 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void	signals_handler(int signal_type, siginfo_t *info)
{
	static int				client_pid;
	static int				i;
	static unsigned char	c;

	if (!client_pid)
		client_pid = info->si_pid;
	if (signal_type == SIGUSR1)
		c = (c * 2) + 1;
	else if (signal_type == SIGUSR2)
		c = (c * 2);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (!c)
		{
			write(1, "\n", 1);
			kill(client_pid, SIGUSR2);
			client_pid = 0;
		}
		i = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	action;

	(void)ac;
	(void)av;
	printf("SERVER PID : %d\n", getpid());
	action.sa_handler = (void *)signals_handler;
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}
