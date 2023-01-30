/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:57:57 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/30 21:47:22 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	signals_handler(int signal_type, siginfo_t *info, void *context)
{
	static int				client_pid;
	static int				i;
	static unsigned char	c;

	(void)context;
	if (client_pid != info->si_pid)
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
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	ft_putstr_fd("SERVER PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("", 1);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = signals_handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
