/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:57:57 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/12/15 17:49:59 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

struct server_data
{
    unsigned char c;
    int i ;
}   data;

void handle_siguser1(int sig)
{

    if (sig == 30)
        data.c = (data.c * 2) + 0;
    else if (sig == 31)
        data.c = (data.c * 2) + 1;
    data.i++;
}

int main()
{
    printf("%d\n", getpid());

    signal(SIGUSR1, handle_siguser1);
    signal(SIGUSR2, handle_siguser1);

    while (1)
    {
        sleep(2);
        if (data.i == 8)
        {
            if(data.c == 0)
            {
               printf("\n"); 
            }
            printf("%c", data.c);
            data.c = 0;
            data.i = 0;
        }
    }
    return 0;
}