/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:57:57 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/12/19 18:10:51 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void signals_handler(int signal_type, siginfo_t *info)
{
    static int i;
    static int c;
    static int client_pid;

    if (!client_pid)
        client_pid = info->si_pid;

    if (signal_type == SIGUSR1)
        c = c * 2 + 1;
    else if (signal_type == SIGUSR2)
        c = c * 2;
    i++;

    if (i == 8)
    {
        if (c == '\0')
        {
            write(1, "\n", 1);
            client_pid = 0;
        }
        else
            write(1, &c, 1);
        i = 0;
        c = 0;
    }
    usleep(10);
    kill(client_pid, SIGUSR2);
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    printf("SERVER PID : %d\n", getpid());

    struct sigaction action;

    action.sa_handler = (void *)signals_handler;

    while (1)
    {
        sigaction(SIGUSR1, &action, NULL);
        sigaction(SIGUSR2, &action, NULL);
    }
    return 0;
}