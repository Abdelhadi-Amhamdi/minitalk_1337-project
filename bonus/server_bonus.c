/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:29:57 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/28 22:30:50 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

int calc_nbytes(unsigned char c)
{
	c = c >> 4;
	if(c == 8)
		return (1);
	else if(c == 12)
		return (2);
	else if(c == 14)
		return (3);
	else if(c == 15)
		return (4);
	return (0);
}

void	signals_handler(int signal_type, siginfo_t *info)
{
	static int				client_pid;
	static int				i;
	static unsigned char c;
	static char *unicode;
	static int is_unicode;
	static int nbyte;
	static int index;

	if (!client_pid)
		client_pid = info->si_pid;
	if(client_pid != info->si_pid)
	{
		c = 0;
		i = 0;
		if(unicode)
		{
			free(unicode);
			unicode = NULL;
		}
		index = 0;
		is_unicode = 0;
		nbyte = 0;	
		client_pid = info->si_pid;
	}
	if (signal_type == SIGUSR1)
		c = (c * 2) + 1;
	else if (signal_type == SIGUSR2)
		c = (c * 2);
	i++;
	if (i == 8)
	{
		if(c < 128 && !is_unicode)
		{
			write(1, &c, 1);
			if (!c)
				client_pid = 0;
		}
		else if(c > 127 && !is_unicode)
		{	
			nbyte = calc_nbytes(c);
			unicode = calloc(nbyte + 1 , sizeof(char));
			unicode[index] = c;
			index++;
			is_unicode = 1;
			nbyte--;
		}
		else
		{
			unicode[index] = c;
			index++;
			nbyte--;
			if(!nbyte)
			{
				ft_putstr_fd(unicode, 1);
				unicode[index] = 0;
				is_unicode = 0;
				unicode = 0;
				index = 0;
				free(unicode);
				unicode = NULL;
			}
		}
		i = 0;
		c = 0;
	}
}

int	main()
{
	struct sigaction	action;

	ft_putstr_fd("SERVER PID: ", 1);
	printf("%d\n", getpid());
	// ft_putnbr_fd(getpid(), 1);
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