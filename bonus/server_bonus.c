/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:29:57 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/31 10:18:12 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

int	calc_nbytes(unsigned char byte)
{
	byte = byte >> 4;
	if (byte == 8)
		return (1);
	else if (byte == 12)
		return (2);
	else if (byte == 14)
		return (3);
	else if (byte == 15)
		return (4);
	return (0);
}

void	ft_clean(char *unicode, int *index, int *nbyte)
{
	if (unicode)
		free(unicode);
	*unicode = NULL;
	*index = 0;
	*nbyte = 0;
}

void	handle_unicode(unsigned char byte)
{
	static char				*unicode;
	static int				nbyte;
	static int				index;

	if (!byte)
		ft_clean(unicode, &index, &nbyte);
	else if (byte < 128 && !nbyte)
		write(1, &byte, 1);
	else if (byte > 127 && !nbyte)
	{
		nbyte = (calc_nbytes(byte) - 1);
		unicode = ft_calloc((nbyte + 2), sizeof(char));
		unicode[index++] = byte;
	}
	else
	{
		unicode[index++] = byte;
		nbyte--;
		if (!nbyte)
		{
			ft_putstr_fd(unicode, 1);
			ft_clean(&unicode, &index, &nbyte);
		}
	}
}

void	signals_handler(int signal_type, siginfo_t *info, void *context)
{
	static int				client_pid;
	static int				index;
	static unsigned char	byte;

	(void)context;
	if (client_pid != info->si_pid)
	{
		byte = 0;
		index = 0;
		handle_unicode(0);
		client_pid = info->si_pid;
	}
	if (signal_type == SIGUSR1)
		byte = (byte * 2) + 1;
	else if (signal_type == SIGUSR2)
		byte = (byte * 2);
	if (++index == 8)
	{
		if (!byte && kill(client_pid, SIGUSR2) == -1)
			exit (1);
		else
			handle_unicode(byte);
		index = 0;
		byte = 0;
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
