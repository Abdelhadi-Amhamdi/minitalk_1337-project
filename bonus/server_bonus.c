/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:29:57 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/26 22:31:00 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

void	signals_handler(int signal_type, siginfo_t *info)
{
	static int				client_pid;
	static int				i;
	static unsigned char	c;

	if (!client_pid)
		client_pid = info->si_pid;
	if(client_pid != info->si_pid)
	{
		c = 0;
		i = 0;
		client_pid = info->si_pid;
	}
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
			client_pid = 0;
		}
		i = 0;
		c = 0;
	}
}

int	main()
{
	struct sigaction	action;

	ft_putstr_fd("SERVER PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("", 1);
	action.sa_flags = SA_RESTART;
	action.sa_sigaction = (void *)signals_handler;
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}