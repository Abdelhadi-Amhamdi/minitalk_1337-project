/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:57:57 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/12/15 19:25:57 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

struct server_data
{
    unsigned char c;
    int index ;
}   data;

void handle_siguser(int sig)
{
    if (sig == 30)
        data.c = (data.c * 2) + 0;
    else if (sig == 31)
        data.c = (data.c * 2) + 1;
    data.index++;
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    printf("%d\n", getpid());

    struct siginfo_t *action;
    


    // sigaction(SIGUSR1, &action, NULL);
    // sigaction(SIGUSR2, &action, NULL);


    
    signal(SIGUSR1, handle_siguser);
    signal(SIGUSR2, handle_siguser);

    while (1)
    {
        sleep(2);
        if (data.index == 8)
        {
            if(data.c == 0)
            {
                printf("\n");
            }
            printf("%c", data.c);
            data.index = 0;
        }
    }
    return 0;
}